// -*- tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*-
// vi: set et ts=4 sw=2 sts=2:
#ifndef __GRID_HH__
#define __GRID_HH__

namespace Dune
{

    /** @defgroup GridCommon Dune Grid Module
          Dune网格模块定义了一个分层有限元网格的通用接口。
          该接口与尺寸和元素类型无关。这个接口有多种实现方式。

          - 结构化网格（SGrid）：一个由 "立方体 "组成的d维结构化网格。每个维度的元素数量是可变的。

          - Albert Grid (AlbertGrid) : 提供由Kunibert Siebert和Alfred Schmidt编写的有限元工具箱ALBERT的简单网格。

          - UG网格（UGGrid）：提供有限元工具箱UG的网格。

          - 结构化并行网格（SPGrid）：提供分布式结构化网格。

          本模块仅包含对所有网格接口实现所共有的化合物的描述。

          关于接口本身的详细描述，请参见 "结构化网格模块 "的文档。由于Dune使用引擎的概念，所以没有抽象的接口定义。与STL容器一样，所有的实现都必须以完全相同的成员实现相同的类，以便在通用算法中使用。

          类图：图像包含见第92页的doxygen doc。

          @{
   */

    //************************************************************************
    /*! \enum ElementType
      宣布不同元素类型的标识符的枚举。这个
      列表可以在将来被扩展。不是所有的网格都需要实现
      所有的元素类型。
   */

    enum ElementType
    {
        unknown,
        line,
        triangle,
        quadrilateral,
        tetrahedron,
        pyramid,
        prism,
        hexahedron,
        iso_triangle,
        iso_quadrilateral
    };

    /** @} */

}

#endif
