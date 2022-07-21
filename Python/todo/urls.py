from django.urls import path
from . import views

urlpatterns = [
    path('', views.entry_list, name='entry_list'),
    path('filtered_list/?P<str:id>', views.filtered_list, name='filtered_list'),
    path('add_entry', views.add_entry, name='add_entry'),
    path('update_entry/?P<int:id>', views.update_entry, name='update_entry'),
    path('delete_entry/?P<int:id>', views.delete_entry, name='delete_entry'),
]