# Generated by Django 3.2.14 on 2022-07-19 14:03

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('todo', '0006_remove_entry_updated_on'),
    ]

    operations = [
        migrations.AlterField(
            model_name='entry',
            name='id',
            field=models.AutoField(primary_key=True, serialize=False),
        ),
    ]
