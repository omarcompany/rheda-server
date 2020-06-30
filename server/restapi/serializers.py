from rest_framework import serializers
from .models import Account, Messages


class AccountSerializer(serializers.ModelSerializer):
    class Meta:
        model = Account
        fields = '__all__'

    def create(self, validated_data):
        print(validated_data)
        user = Account(name=validated_data['name'])
        user.save()
        return user


class MessageSerializer(serializers.ModelSerializer):
    class Meta:
        model = Messages
        fields = '__all__'

    def create(self, validated_data):
        message = Messages(
            sender=validated_data['sender'],
            recipient=validated_data['recipient'],
            text=validated_data['text'],
        )
        message.save()
        return message
