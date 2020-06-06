from rest_framework import serializers
from .models import Account, Message


class AccountSerializer(serializers.ModelSerializer):
    class Meta:
        model = Account
        fields = '__all__'

    def create(self, validated_data):
        print(validated_data)
        user = Account(name=validated_data['name'],)
        user.save()
        return user

class MessageSerializer(serializers.ModelSerializer):
    class Meta:
        model = Message
        fields = '__all__'

    def create(self, validated_data):
        print(validated_data)
        message = Message(
            authorName=validated_data['authorName'],
            authorId=validated_data['authorId'],
            timestamp=validated_data['timestamp'],
            text=validated_data['text'],
        )
        message.save()
        return message
