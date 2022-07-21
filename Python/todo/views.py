from django.shortcuts import render
from .models import Entry
from django.contrib.auth.models import User
from django.shortcuts import redirect
from django.utils import timezone


# Create your views here.
def entry_list(request):
    user = User.objects.get(username='Aravind')

    if request.method == 'POST':
        entrys = Entry.objects.filter(title=request.POST.get('searchTitle'))
        return render(request,'todo/entry_list.html',{'entrys':entrys})

    entrys = Entry.objects.order_by('-posted_on')
    return render(request,'todo/entry_list.html',{'entrys':entrys})

def filtered_list(request,id):
    entrys = Entry.objects.filter(status=id)
    return render(request,'todo/entry_list.html',{'entrys':entrys})

def add_entry(request):
    if request.method == 'POST':
        entry = Entry()
        user = User.objects.get(username='Aravind')
        entry.author = user
        entry.title = request.POST.get('title')
        entry.text = request.POST.get('description')
        entry.status = request.POST.get('status')
        entry.posted_on = timezone.now()
        entry.save()
        entrys = Entry.objects.filter(author=user)
        entrys = Entry.objects.order_by('-posted_on')   
        return render(request,'todo/entry_list.html',{'entrys':entrys})
    return render(request,'todo/add_entry.html',{})

def update_entry(request,id):
    entry = Entry.objects.filter(id=id)
    if request.method == 'POST':
        posted_time = entry[0].posted_on
        entry = Entry()
        user = User.objects.get(username='Aravind')
        entry.author = user
        entry.id = id
        entry.title = request.POST.get('title')
        entry.text = request.POST.get('description')
        entry.status = request.POST.get('status')
        entry.posted_on = posted_time
        entry.save()
        entrys = Entry.objects.order_by('-posted_on')
        return render(request,'todo/entry_list.html',{'entrys':entrys})

    return render(request,'todo/update_entry.html',{'title':entry[0].title, 'description':entry[0].text,
    'status':entry[0].status})

def delete_entry(request,id):
    Entry.objects.filter(id=id).delete()
    user = User.objects.get(username='Aravind')
    entrys = Entry.objects.filter(author=user)
    return redirect(entry_list)
