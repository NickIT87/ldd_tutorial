#include <Python.h>

/* функция на C */
static PyObject* fast_add(PyObject* self, PyObject* args) {
    int a, b;

    if (!PyArg_ParseTuple(args, "ii", &a, &b)) {
        return NULL;
    }

    int result = a + b;

    return PyLong_FromLong(result);
}

/* таблица методов */
static PyMethodDef FastMethods[] = {
    {"add", fast_add, METH_VARARGS, "Add two integers"},
    {NULL, NULL, 0, NULL}
};

/* описание модуля */
static struct PyModuleDef fastmodule = {
    PyModuleDef_HEAD_INIT,
    "fastmath",
    "Example C extension module",
    -1,
    FastMethods
};

/* точка инициализации */
PyMODINIT_FUNC PyInit_fastmath(void) {
    return PyModule_Create(&fastmodule);
}