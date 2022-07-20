from django.conf import settings
from django.db import models
from django.utils import timezone

class Entry(models.Model):
    id = models.AutoField(primary_key=True)
    author = models.ForeignKey(settings.AUTH_USER_MODEL, on_delete=models.CASCADE)
    title = models.CharField(max_length=200)
    text = models.TextField()
    posted_on = models.DateTimeField(default=timezone.now)
    status = models.CharField(max_length=200,default="Basic",choices=[('Important', 'Important'),('Basic', 'Basic'),('Urgent', 'Urgent')])

    def updateEntry(self):
        self.updated_on =  timezone.now()
        self.save()
    
    def __str__(self):
        return self.title


