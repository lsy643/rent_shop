cc_library(
    name = "movie",
    srcs = ["movie.cc"],
    hdrs = ["movie.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "rental",
    srcs = ["rental.cc"],
    hdrs = ["rental.h"],
    deps = [":movie"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "customer",
    srcs = ["customer.cc"],
    hdrs = ["customer.h"],
    deps = [":rental"],
    visibility = ["//visibility:public"],
)