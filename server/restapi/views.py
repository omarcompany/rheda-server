from rest_framework import generics
from .serializers import AccountSerializer, MessageSerializer
from .models import Messages


class UserView (generics.CreateAPIView):
    serializer_class = AccountSerializer


class MessageView(generics.CreateAPIView):
    serializer_class = MessageSerializer


'''
Запрос на вывод истории переписки (messageList)
Пример запроса:
http://127.0.0.1:8000/api/messageList?recipient=<recipient_id>
'''


class MessageListView(generics.ListAPIView):
    '''Возвращает клиенту все сообщения, которые адркссуются ему'''
    serializer_class = MessageSerializer

    def get_queryset(self):
        queryset = Messages.objects.all()
        recipient = self.request.query_params.get('recipient', None)
        sender = self.request.query_params.get('sender', None)

        if sender is not None:
            queryset = queryset.filter(sender_id=sender)
        if recipient is not None:
            queryset = queryset.filter(recipient_id=recipient)

        return queryset
