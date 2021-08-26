//
// Created by yangjianshan on 2021/8/25.
//

#include <boost/python.hpp>
#include "main.cpp"

void HelloObject_using_signal_sg_2(HelloObject& self, boost::python::object obj){
    self.using_signal_sg_1(obj);
}

BOOST_PYTHON_MODULE(hello_ext){
    namespace python = boost::python;
//    def("hello", hello);

    python::class_<World>("World", python::init<>())
            .def("greet", &World::greet)
            .def("set", &World::set);


    python::class_<HelloObject>("HelloObject", python::init<>())
            .def("using_signal_sg_1", &HelloObject_using_signal_sg_2)
            .def("using_signal_sg_2", &HelloObject::using_signal_sg_2)
            .def("get_counter", &HelloObject::get_counter)
            .def("run", &HelloObject::run)
            .def("world", &HelloObject::world);
}