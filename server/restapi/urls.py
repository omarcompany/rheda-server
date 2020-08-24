from django.urls import path
from .views import UserView, MessageView, MessageListView


urlpatterns = [
    path("signup", UserView.as_view(), name="Create_Account"),
    path("message", MessageView.as_view(), name="Send_Message"),
    path("messageList", MessageListView.as_view(), name="message_list"),
]
