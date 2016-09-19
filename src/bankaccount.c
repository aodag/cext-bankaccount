// #define Py_LIMITED_API
#include "Python.h"

typedef struct {
  PyObject_HEAD
  int balance;
} bankaccount_BankAccountObject;

static PyObject*
deposit(bankaccount_BankAccountObject *self, PyObject *args)
{
  int amount = 0;
  PyArg_ParseTuple(args, "i", &amount);
  self->balance += amount;
  Py_RETURN_NONE;
}

static PyObject*
withdraw(bankaccount_BankAccountObject *self, PyObject *args)
{
  int amount = 0;
  PyArg_ParseTuple(args, "i", &amount);
  self->balance -= amount;
  Py_RETURN_NONE;
}
static PyObject*
balance(bankaccount_BankAccountObject *self, PyObject *args)
{
  return Py_BuildValue("i", self->balance);
}

static PyMethodDef methods[] = {
  {"deposit", (PyCFunction)deposit, METH_VARARGS,
   "deposit amount"},
  {"withdraw", (PyCFunction)withdraw, METH_VARARGS,
   "withdraw amount"},
  {"balance", (PyCFunction)balance, METH_NOARGS,
   "returns current balance"},
  {NULL}
};

static PyTypeObject bankaccount_BankAccountType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "bankaccount.BankAccount",             /* tp_name */
    sizeof(bankaccount_BankAccountObject), /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_as_async */
    0,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    0,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,        /* tp_flags */
    "Noddy objects",           /* tp_doc */
};

static struct PyModuleDef bankaccountmodule = {
  PyModuleDef_HEAD_INIT,
  "bankaccount",
  NULL,
  -1,
  NULL, NULL, NULL, NULL, NULL
};

PyMODINIT_FUNC
PyInit__bankaccount(void)
{
  PyObject *m = PyModule_Create(&bankaccountmodule);
  bankaccount_BankAccountType.tp_new = PyType_GenericNew;
  bankaccount_BankAccountType.tp_methods = methods;
  PyType_Ready(&bankaccount_BankAccountType);
  Py_INCREF(&bankaccount_BankAccountType);
  PyModule_AddObject(m, "BankAccount", (PyObject *)&bankaccount_BankAccountType);
  return m;
}
