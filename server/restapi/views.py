from rest_framework import generics
from .serializers import AccountSerializer


class UserView (generics.CreateAPIView):
    serializer_class = AccountSerializer
