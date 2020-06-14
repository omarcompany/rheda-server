from django.test import TestCase
from django.test import Client


class SignupTestCase(TestCase):
    def test_user_can_signup(self):
        """User can signup with any name and receive id"""
        с = Client()
        request = {'name': 'Vlad МС'}
        response = с.post('/api/signup', request)

        self.assertEqual(response.status_code, 201)
        self.assertEqual(response.json()["name"], request["name"])

    def test_user_error_on_empty_name(self):
        """Error on empty name"""
        c = Client()
        response = c.post('/api/signup', {'name': ''})
        self.assertEqual(response.status_code, 400)


class SendMessageTestCase(TestCase):
    """User can send message to another user"""
    def test_user_can_send_message(self):
        c = Client()
        # Signup sender test user
        senderRequest = {'name': 'Dukalis'}
        senderResponse = c.post('/api/signup', senderRequest)
        senderId = senderResponse.json()['id']

        # Signup recipient test user
        recipientRequest = {'name': 'Andryukha'}
        recipientResponse = c.post('/api/signup', recipientRequest)
        recipientId = recipientResponse.json()['id']

        # Sending message
        senderRequest = {
            'sender': str(senderId),
            'recipient': str(recipientId),
            'text': 'Andryukha, we have a corpse.'
        }

        senderResponse = c.post('/api/message', senderRequest)
        self.assertEqual(senderResponse.status_code, 201)
        self.assertEqual(senderResponse.json()['text'],
                         senderRequest['text'])
