// -*- tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*-
// vi: set et ts=4 sw=2 sts=2:
#ifndef __MATVEC_HH__
#define __MATVEC_HH__

namespace Dune
{
    /** @defgroup Common Dune Common Module

          这个模块包含了在dune中一般使用的类，比如说 (小）密集的矩阵和向量或容器。

          @{
   */

    //************************************************************************
    /*!
     通用的向量类，用于d维的短向量。例如，用于全局或局部坐标。
   */
    template <int n, class T = double>
    class Vec
    {
    public:
        //! 构造函数制作未被初始化的向量
        Vec() {}

        //! 构造函数从内置数组assign向量
        Vec(T *y)
        {
            for (int i = 0; i < n; i++)
                x[i] = y[i];
        }

        //! 构造函数使向量初始化，并在特定序列赋值
        Vec(int k, T t)
        {
            for (int i = 0; i < n; i++)
                x[i] = 0, x[k] = t;
        }

        //! 构造函数，制造具有相同数值的向量
        Vec(T t)
        {
            for (int i = 0; i < n; i++)
                x[i] = t;
        }

        //! operator () 用来对向量元素的读/写访问
        T &operator()(int i) { return x[i]; }

        //! operator+ 两个向量加法运算
        Vec<n, T> operator+(const Vec<n, T> &b)
        {
            Vec<n, T> z;
            for (int i = 0; i < n; i++)
                z.x[i] = x[i] + b.x[i];
            return z;
        }

        //! operator- 二元减法
        Vec<n, T> operator-(const Vec<n, T> &b)
        {
            Vec<n, T> z;
            for (int i = 0; i < n; i++)
                z.x[i] = x[i] - b.x[i];
            return z;
        }

        //! 两个向量的标量乘以运算符*
        T operator*(const Vec<n, T> &b)
        {
            T s = 0;
            for (int i = 0; i < n; i++)
                s += x[i] * b.x[i];
            return s;
        }

        //! 向量与标量的乘法
        T operator*(T k)
        {
            Vec<n, T> z;
            for (int i = 0; i < n; i++)
                z.x[i] = k * x[i];
            return s;
        }

    private:
        //! 内置数组来保存数据。
        T x[n];
    };

    //! 标量与矢量的乘法
    template <int n, class T>
    Vec<n, T> operator*(T k, Vec<n, T> b)
    {
        Vec<n, T> z;
        for (int i = 0; i < n; i++)
            z(i) = k * b(i);
        return z;
    }

    //! 一元减法
    template <int n, class T>
    Vec<n, T> operator-(Vec<n, T> b)
    {
        Vec<n, T> z;
        for (int i = 0; i < n; i++)
            z(i) = -b(i);
        return z;
    }

    //************************************************************************
    /*!
     通用的向量类，用于d维的短向量。例如，用于全局或局部坐标。
   */
    template <int n, int m, class T = double>
    class Mat
    {
    public:
        //! 构造函数制作未被初始化的矩阵
        Mat() {}

        //! operator () for 用来对矩阵元素的读/写访问
        T &operator()(int i, int j) { return a[j](i); }

        //! operator () for 对列向量的读/写访问
        Vec<n, T> &operator()(int j) { return a[j]; }

        //! 矩阵/向量乘法
        Vec<n, T> operator*(const Vec<m, T> &x)
        {
            Vec<n, T> z(0.0);
            for (j = 0; j < m; j++)
                for (i = 0; i < n; i++)
                    z(i) += a[j](i) * x(j);
            return z;
        }

    private:
        //! 内置数组，用于保存数据
        Vec<n, T> a[m];
    };

    /** @} */

}

#endif
