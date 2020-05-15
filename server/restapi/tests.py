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
