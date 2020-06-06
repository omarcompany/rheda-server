import uuid
from django.db import models
from django.utils import timezone


class Account(models.Model):
    id = models.UUIDField(primary_key=True,
                          verbose_name='id',
                          editable=False,
                          default=uuid.uuid4)
    name = models.CharField(verbose_name='name', max_length=100)
    created_at = models.DateTimeField(verbose_name='created_at',
                                      editable=False,
                                      default=timezone.now)

class Message(models.Model):
    authorName = models.CharField(verbose_name='authorName', max_length=100)
    authorId = models.ForeignKey(Account, default=None, on_delete=models.CASCADE)
    timestamp = models.DateTimeField(verbose_name='timestamp', default=timezone.now)
    text = models.TextField(verbose_name='text')