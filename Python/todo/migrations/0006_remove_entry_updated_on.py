# Generated by Django 3.2.14 on 2022-07-19 10:10

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('todo', '0005_alter_entry_status'),
    ]

    operations = [
        migrations.RemoveField(
            model_name='entry',
            name='updated_on',
        ),
    ]
