# Smol Core2D

This is a C++20 header-only library I created so I could reuse various basic structs I keep adding to my projects that make dealing with 2D space easier and more convenient. Notably, it includes template class implementations for a 2D vector type, a size type, and a rectangle type.

## Installation

This library uses CMake as its build system, so you can simply git clone it and then build & install it locally. Alternatively, since this is a header-only library, copy-pasting the headers you want into your project will suffice.

## Usage

Either include the main header file or the headers of individual structs. Note that including the main header also defines type aliases that use int and float as our structs' underlying value types in the parent `Smol` namespace. Only including individual structs does not define these aliases and does not put anything in the parent namespace, only defining things in `Smol::Core2D`.

```C++
#include <smol/core2d.hpp>
// Smol::Vec2I, Smol::Vec2F, Smol::RectI, Smol::RectF, etc. are available from now on.
```

```C++
#include <smol/core2d/vec2.hpp>
// Only Smol::Core2D::Vec2 is available from now on.

...

#include <smol/core2d/size.hpp>
// Only Smol::Core2D::Size is available from now on.

...

#include <smol/core2d/rect.hpp>
// Only Smol::Core2D::Rect is available from now on.
```

Since this library is still in its infancy, it does not yet have documentation that covers 100% (or any percent for that matter) of its public functions.