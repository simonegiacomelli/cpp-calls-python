#include <iostream>
#include <pybind11/embed.h>

namespace py = pybind11;

int main() {
    py::scoped_interpreter guard{}; // Start Python interpreter
    py::exec(R"(
        print("Hello from Python!")
        # Import and use your Python program here
    )");
    py::module sys = py::module::import("sys");
    sys.attr("path").attr("append")("/home/simone/CLionProjects/untitled3/python");
    py::module my_module = py::module::import("my_python_module");
    auto result = my_module.attr("my_python_function")();
    std::cout << "Result: " << result.cast<std::string>() << std::endl;
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
