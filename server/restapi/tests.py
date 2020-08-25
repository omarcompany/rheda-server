from django.test import TestCase
from django.test import Client


class SignupTestCase(TestCase):
    def test_user_can_signup(self):
        """User can signup with any name and receive id"""
        c = Client()
        request = {'name': 'Vlad МС'}
        response = c.post('/api/signup', request)

        self.assertEqual(response.status_code, 201)
        self.assertEqual(response.json()["name"], request["name"])

    def test_user_error_on_empty_name(self):
        """Error on empty name"""
        c = Client()
        response = c.post('/api/signup', {'name': ''})
        self.assertEqual(response.status_code, 400)

    def test_user_can_get_account_list(self):
        """User can signup with any name and receive id"""
        c1 = Client()
        request1 = {'name': 'Vlad'}
        c1.post('/api/signup', request1)

        c2 = Client()
        request2 = {'name': 'Bran'}
        c2.post('/api/signup', request2)

        c3 = Client()
        response = c3.get('/api/accountList')

        self.assertEqual(response.status_code, 200)


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

    def test_user_can_get_message_list(self):
        """user can get message list"""
        client = Client()

        # Signup sender test user
        sender_request = {'name': 'Dukalis'}
        sender_response = client.post('/api/signup', sender_request)
        sender_id = sender_response.json()['id']

        # Signup recipient test user
        recipient_request = {'name': 'Andryukha'}
        recipient_response = client.post('/api/signup', recipient_request)
        recipient_id = recipient_response.json()['id']

        # Sending messages
        messages = [
            'Andryukha, we have a corpse.',
            'Possibly a crime!',
            'On the horses!'
        ]
        for message in messages:
            sender_request = {
                'sender': str(sender_id),
                'recipient': str(recipient_id),
                'text': message
            }
            client.post('/api/message', sender_request)

        # Geting messages
        get_response = client.get(
            f'/api/messageList?recipient={recipient_id}').json()

        for i in range(len(get_response)):
            self.assertEqual(messages[i], get_response[i]['text'])
