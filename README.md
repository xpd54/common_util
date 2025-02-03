# Common Util

Common header only C++ util which can be reused.

### Table of Contents

- [How to use](#how-to-use)
- [Header Details](#header-details)
- [License](#license)

#### How-To-Use

`git submodule add https://github.com/xpd54/common_util.git`

```cmake
#if cloned in an external folder

add_subdirectory(external/common_util)
include_directories(
  external/common_util/include
)
target_link_libraries(${PROJECT_NAME}
  PUBLIC
  common_util
 )
```

#### Header-Details

| Header                 | Quick Details                                                                      | Link/Example Code                                                                                                                                    |
| :--------------------- | :--------------------------------------------------------------------------------- | :--------------------------------------------------------------------------------------------------------------------------------------------------- |
| command_line_util.hpp  | Read command line arguments from the main method.                                  | [here](https://github.com/xpd54/backtesting/blob/29744b2e367d9e938b3b53130ab491e4cb233273/data_generator/main.cpp#L260)                              |
| Logger.hpp             | singleton instance based logging library                                           | [here](https://github.com/xpd54/backtesting/blob/29744b2e367d9e938b3b53130ab491e4cb233273/data_generator/main.cpp#L255)                              |
| memory_map_util.hpp    | map a file from disk to memory space. It's probably the fastest way to read files. | [here](https://github.com/xpd54/backtesting/blob/29744b2e367d9e938b3b53130ab491e4cb233273/backtesting/base/util/binary_io/binary_read_write.hpp#L16) |
| string_format_util.hpp | accepts built-in data type in varadic template and returns a string.               | [here](https://github.com/xpd54/backtesting/blob/29744b2e367d9e938b3b53130ab491e4cb233273/backtesting/main.cpp#L31)                                  |
| time_util.hpp          | quick operation on time                                                            | [here](https://github.com/xpd54/backtesting/blob/29744b2e367d9e938b3b53130ab491e4cb233273/backtesting/main.cpp#L108)                                 |

#### LICENSE

[Licence](https://github.com/xpd54/common_util/blob/main/LICENSE)
