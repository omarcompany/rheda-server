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
