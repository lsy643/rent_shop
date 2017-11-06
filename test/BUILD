cc_test(
    name = "test_hello",
    srcs = ["test_hello.cc"],
    copts = ["-Iexternal/gtest/include"],
    deps = [
        "@gtest//:main",
        "//lib:hello-greet",
    ],
)

cc_test(
    name = "test_customer",
    srcs = ["test_customer.cc"],
    copts = ["-Iexternal/gtest/include"],
    deps = [
        "@gtest//:main",
        "//src:movie",
        "//src:rental",
        "//src:customer"
    ],
)