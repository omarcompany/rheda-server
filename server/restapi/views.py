from rest_framework import generics
from .serializers import AccountSerializer, MessageSerializer


class UserView (generics.CreateAPIView):
    serializer_class = AccountSerializer


class MessageView(generics.CreateAPIView):
    serializer_class = MessageSerializer
