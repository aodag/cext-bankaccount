import unittest


class TestBankAccount(unittest.TestCase):
    def _getTarget(self):
        from bankaccount import BankAccount
        return BankAccount

    def _makeOne(self, *args, **kwargs):
        return self._getTarget()(*args, **kwargs)

    def test_init(self):
        target = self._makeOne()
        self.assertEqual(0, target.balance())

    def test_deposit(self):
        target = self._makeOne()
        target.deposit(100)
        self.assertEqual(100, target.balance())

    def test_withdraw(self):
        target = self._makeOne()
        target.withdraw(100)
        self.assertEqual(-100, target.balance())
