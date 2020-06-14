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


class Messages(models.Model):
    sender = models.ForeignKey(Account,
                               on_delete=models.CASCADE,
                               null=False,
                               related_name='sender')
    recipient = models.ForeignKey(Account,
                                  on_delete=models.CASCADE,
                                  null=False,
                                  related_name='recipient')
    created_at = models.DateTimeField(verbose_name='created_at',
                                      editable=False,
                                      default=timezone.now)
    text = models.TextField(verbose_name='text', null=False)
