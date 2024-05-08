<a id="readme-top" name="readme-top"></a>

<!-- ------------------------------
* TITLE, DESCRIPTION & CONTACT
------------------------------ -->
# 💽 C++

<br>

This project brings together all the C++ modules, each with several exercises. It provides an **in-depth, complete and advanced understanding of C++**, including **basics, object-oriented programming, operator overloads, complex inheritances, exceptions, casts, iterators, templates, subtyping, containers from STL** and much more.

<br>

<!-- ------------------------------
* TABLE OF CONTENTS
------------------------------ -->
## 📋 Table of contents

- [**👀 Overview**](#readme-overview)
- [**📦 Requirements**](#readme-requirements)
- [**💾 Installation**](#readme-installation)
- [**🛠️ Makefile**](#readme-makefile)
- [**📄 License**](#readme-license)


<a id="readme-overview" name="readme-overview"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* OVERVIEW
------------------------------ -->
## 👀 Overview

<table>
    <tr>
        <th align="left" width="7000">Module</th>
        <th align="left" width="3000">Score</th>
    </tr>
    <tr>
        <td><a href="/cpp00">C++ Module 00</a></td>
        <td>✅ <b>100</b> / 100</td>
    </tr>
    <tr>
        <td><a href="/cpp01">C++ Module 01</a></td>
        <td>✅ <b>100</b> / 100</td>
    </tr>
    <tr>
        <td><a href="/cpp02">C++ Module 02</a></td>
        <td>✅ <b>100</b> / 100</td>
    </tr>
    <tr>
        <td><a href="/cpp03">C++ Module 03</a></td>
        <td>✅ <b>100</b> / 100</td>
    </tr>
    <tr>
        <td><a href="/cpp04">C++ Module 04</a></td>
        <td>✅ <b>100</b> / 100</td>
    </tr>
    <tr>
        <td><a href="/cpp05">C++ Module 05</a></td>
        <td>✅ <b>100</b> / 100</td>
    </tr>
    <tr>
        <td><a href="/cpp06">C++ Module 06</a></td>
        <td>✅ <b>100</b> / 100</td>
    </tr>
    <tr>
        <td><a href="/cpp07">C++ Module 07</a></td>
        <td>✅ <b>100</b> / 100</td>
    </tr>
    <tr>
        <td><a href="/cpp08">C++ Module 08</a></td>
        <td>✅ <b>100</b> / 100</td>
    </tr>
    <tr>
        <td><a href="/cpp09">C++ Module 09</a></td>
        <td>✅ <b>100</b> / 100</td>
    </tr>
</table>

<a id="readme-requirements" name="readme-requirements"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* REQUIREMENTS
------------------------------ -->
## 📦 Requirements

```
sudo apt -y install clang-12 make
```

<a id="readme-installation" name="readme-installation"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* INSTALLATION
------------------------------ -->
## 💾 Installation

**1. Get the project**

```
git clone https://github.com/rilemko/42-cpp.git
```

<br>

**2. Build an exercise:**

```
make -j$(nproc)
```

> **🟡 Important:** Each exercise must be built independently **from its own directory**.

> **🔵 Info:** Each executable will be created in the directory of the exercise concerned.

<a id="readme-makefile" name="readme-makefile"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* MAKEFILE
------------------------------ -->
## 🛠️ Makefile

<table>
    <tr>
        <th align="left" width="500px">Rule</th>
        <th align="left" width="9500px">Action</th>
        </tr>
    <tr><td><code>all</code></td><td>Compile.</td></tr>
    <tr><td><code>clean</code></td><td>Delete all generated object files</td></tr>
    <tr><td><code>fclean</code></td><td>Apply <code>clean</code>, <code>lclean</code> and delete the executable.</td></tr>
    <tr><td><code>lclean</code></td><td>Apply <code>fclean</code> to all used libraries.</td></tr>
    <tr><td><code>re</code></td><td>Apply <code>fclean</code> and force recompile.</td></tr>
</table>

<a id="readme-license" name="readme-license"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* LICENSE
------------------------------ -->
## 📄 License

This project is licensed under the terms of the **MIT** license.

[**⛓️ FILE : LICENSE**](LICENSE.md)

<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>
