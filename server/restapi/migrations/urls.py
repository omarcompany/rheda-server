from django.urls import path
from .views import UserCreate

urlpatterns = [
    path("users/registration", UserCreate.as_view(), name="user_create"),
]
