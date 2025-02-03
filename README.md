# Common Util

Common header only c++ util which can be reused.

### Table of Contents

- [How to use](#how-to-use)
- [Header Details](#header-details)
- [License](#license)

#### How-To-Use

`git submodule add https://github.com/xpd54/common_util.git`

```cmake
#if cloned in external folder

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

| Header                 | Quick Details                                                                       | Usecase Code Link/Example |
| :--------------------- | :---------------------------------------------------------------------------------- | :------------------------ |
| command_line_util.hpp  | Read command line arguments from main method.                                       | here                      |
| Logger.hpp             | singleton instance based logging libarary                                           | here                      |
| memory_map_util.hpp    | map a file from disk to memory space. It's probabably the fastest way to read file. | here                      |
| string_format_util.hpp | accepts built in data type in varadic template and return a string.                 | here                      |
| time_util.hpp          | quick operation on time                                                             | here                      |

#### LICENSE

[Licence](https://github.com/xpd54/common_util/blob/main/LICENSE)
