from rest_framework import serializers
from .models import Account


class AccountSerializer(serializers.ModelSerializer):
    class Meta:
        model = Account
        fields = '__all__'

    def create(self, validated_data):
        print(validated_data)
        user = Account(name=validated_data['name'],)
        user.save()
        return user
