# Numerical Methods Console App

This repository features a collection of programs designed to solve numerical problems using widely used methods such as Bi-Section, False position, Newton Raphson, Secant, Gauss Elimination, Gauss jordan Elimination, LU Decomposition, Runge kutta method, Matrix inversion, Newton's Forward and backward interpolation, Newton's Divided difference, Regression, Simpson's Rule, and Differential method. Each method has its own folder containing:

- The theory and description of the method
- C++ code implementation
- Sample input and output files

**Collaborators:**

1. Naurina Haque (Github: [naurina-haque](https://github.com/naurina-haque))
2. Nashita Binte Hamid (Github: [N-nashita](https://github.com/N-nashita))

## Table of Contents
- [Project Structure](#project-structure)
- [Usage](#usage)
- [Solution of Non Linear Equations](#solution-of-non-linear-equations)

  - [Bisection Method](#bisection-method)
    - [Theory](#bisection-theory)
    - [Code](#bisection-code)
    - [Input](#bisection-input)
    - [Output](#bisection-output)
  - [False Position Method](#false-position-method)
    - [Theory](#false-position-theory)
    - [Code](#false-position-code)
    - [Input](#false-position-input)
    - [Output](#false-position-output)
  - [Newton-Raphson Method](#newton-raphson-method)
    - [Theory](#newton-raphson-theory)
    - [Code](#newton-raphson-code)
    - [Input](#newton-raphson-input)
    - [Output](#newton-raphson-output)
  - [Secant Method](#secant-method)
    - [Theory](#secant-theory)
    - [Code](#secant-code)
    - [Input](#secant-input)
    - [Output](#secant-output)

- [Solution of Interpolation Method](#solution-of-interpolation-method)

  - [Newton's Forward Interpolation](#newtons-forward-interpolation)
    - [Theory](#forward-interpolation-theory)
    - [Code](#forward-interpolation-code)
    - [Input](#forward-interpolation-input)
    - [Output](#forward-interpolation-output)
  - [Newton's Backward Interpolation](#newtons-backward-interpolation)
    - [Theory](#backward-interpolation-theory)
    - [Code](#backward-interpolation-code)
    - [Input](#backward-interpolation-input)
    - [Output](#backward-interpolation-output)
  - [Newton's Divided Difference Interpolation](#newtons-divided-difference-interpolation)
    - [Theory](#divided-difference-interpolation-theory)
    - [Code](#divided-difference-interpolation-code)
    - [Input](#divided-difference-interpolation-input)
    - [Output](#divided-difference-interpolation-output)

- [Solution of Numerical Differentiation](#solution-of-numerical-differentiation)

  - [Numerical Differentiation](#numerical-differentiation)
    - [Theory](#numerical-differentiation-theory)
    - [Code](#numerical-differentiation-code)
    - [Input](#numerical-differentiation-input)
    - [Output](#numerical-differentiation-output)

- [Solution of Linear Equations](#solution-of-linear-equations)
  
  - [Gauss Elimination Method](#gauss-elimination-method)
      - [Theory](#gauss-elimination-theory)
      - [Code](#gauss-elimination-code)
      - [Input](#gauss-elimination-input)
      - [Output](#gauss-elimination-output)
  - [Gauss Jordan Elimination Method](#gauss-jordan-elimination-method)
      - [Theory](#gauss-jordan-theory)
      - [Code](#gauss-jordan-code)
      - [Input](#gauss-jordan-input)
      - [Output](#gauss-jordan-output)
  - [LU Decomposition Method](#lu-decomposition-method)
      - [Theory](#lu-decomposition-theory)
      - [Code](#lu-decomposition-code)
      - [Input](#lu-decomposition-input)
      - [Output](#lu-decomposition-output)
  - [Matrix Inversion](#matrix-inversion)
      - [Theory](#matrix-inversion-theory)
      - [Code](#matrix-inversion-code)
      - [Input](#matrix-inversion-input)
      - [Output](#matrix-inversion-output)
     
- [Solution of Numerical Integration](#solution-of-numerical-integration)
  
  - [Simpson's 1/3rd Rule](#simpsons-13rd-rule)
      - [Theory](#simpsons-13rd-theory)
      - [Code](#simpsons-13rd-code)
      - [Input](#simpsons-13rd-input)
      - [Output](#simpsons-13rd-output)
  - [Simpson's 3/8th Rule](#simpsons-38th-rule)
      - [Theory](#simpsons-38th-theory)
      - [Code](#simpsons-38th-code)
      - [Input](#simpsons-38th-input)
      - [Output](#simpsons-38th-output)
     
- [Regression Methods](#regression-methods)
  
  - [Linear Regression](#linear-regression)
      - [Theory](#linear-regression-theory)
      - [Code](#linear-regression-code)
      - [Input](#linear-regression-input)
      - [Output](#linear-regression-output)
  - [Exponential Regression](#exponential-regression)
      - [Theory](#exponential-regression-theory)
      - [Code](#exponential-regression-code)
      - [Input](#exponential-regression-input)
      - [Output](#exponential-regression-output)
  - [Polynomial Regression](#polynomial-regression)
      - [Theory](#polynomial-regression-theory)
      - [Code](#polynomial-regression-code)
      - [Input](#polynomial-regression-input)
      - [Output](#polynomial-regression-output)
      
- [Solution of Ordinary Differential Equations](#solution-of-ordinary-differential-equations)
  - [Runge-Kutta Method](#runge-kutta-method)
    - [Theory](#runge-kutta-theory)
    - [Code](#runge-kutta-code)
    - [Input](#runge-kutta-input)
    - [Output](#runge-kutta-output)
           
---

## Project Structure

```
Numerical-Methods-Console-App/
├── Solution of Non Linear Equations/
│   ├── Bi-section method/
│   ├── False Position Method/
│   ├── Newton-Raphson Method/
│   └── Secant Method/
├── Solution of Interpolation Methods/
│   ├── Newton's Forward Interpolation/
│   ├── Newton's Backward Interpolation/
│   └── Newton's Divided Difference Interpolation/
├── Solution of Numerical Differentiation/
├── Solution of Linear Equations/
│   ├── LU Decomposition/
│   └── Matrix Inversion Method/
├── Solution of Differential Equation/
├── Solution of Curve Fitting(Regression)/
└── Solution of Numerical Integration/
```
[↑ Back to Table of Contents](#table-of-contents)

---


## Usage

## Solution of Non Linear Equations

### Bisection Method

#### Bisection Theory

The bisection method is a type of incremental search method where the interval is repeatedly divided into two equal parts. If the function changes sign over an interval, the function value at the midpoint is calculated. The root is then located in the half where the sign change occurs. This process is repeated to obtain more accurate root values. It is alternatively called binary chopping, interval halving or Bolzano's method.

**Algorithm:**

    Step 1: Select two initial values x1(lower guess) and x2(upper guess) such that f(x1)×f(x2)<0.
    Step 2: For each identified subinterval [x1, x2]:
    Compute the midpoint x0, 
            x0 =(x1+x2)/2
    Step 3: Repeat until fabs(x2-x1) is less than the given tolerance:
    
        (a)	If f(x0) = 0 then the root is x0.
        (b)	If f(x0)*f(x1) < 0 then x2=x0.
        (c)	If f(x0)*f(x2) < 0 then x1=x0.

**Advantages:**

- Simple and accurate for small intervals.
- Works well with tabulated experimental data.
- Useful when analytical differentiation is impossible.

**Limitations:**

- Generally slower than other methods.
- Requires equally spaced data.
- Accuracy decreases for large h.

#### Bisection Code

**Code Link:** [bi_section.cpp](Solution%20of%20Non%20Linear%20Equations/Bi-section%20method/bi_section.cpp)

#### Bisection Input

**Input Format:**

```
<degree_of_polynomial>
<coefficient_n> <coefficient_n-1> ... <coefficient_0>
<lower_bound> <upper_bound>
<max_iterations>
<tolerance>
```

**Example:**

```
2
-10 -4 1
-200 200
1
0.001
```

#### Bisection Output

**Output Format:**

```
=== Bi-section Method ===
Equation is: <equation_representation>
Intervals containing roots: {x1,x2}  {x3,x4}
Roots are:
Root1 = <value>
Root2 = <value>
```



[↑ Back to Table of Contents](#table-of-contents)

---

### False Position Method

#### False Position Theory

The false position method, also known as Regula Falsi method, is a root-finding algorithm that draws a straight line between two points where the function has opposite signs and uses the x-intercept of this line as the next approximation. Instead of dividing the interval into two equal halves like bisection, it uses linear interpolation to find a better approximation of the root.

**Algorithm:**

    Step 1: Select two initial values x1(lower guess) and x2(upper guess) such that f(x1)×f(x2)<0.
    
    Step 2: For each identified subinterval [x1, x2]:
    Compute the new approximation x0 using the formula:
          x0 = x1 - f(x1)\*(x2-x1)/(f(x2)-f(x1))
    
    Step 3: Repeat until fabs(x2-x1) is less than the given tolerance:
    
      (a) If f(x0) = 0 then the root is x0.
      (b) If f(x0)\*f(x1) < 0 then x2=x0.
      (c) If f(x0)\*f(x2) < 0 then x1=x0.

**Advantages:**

- Faster convergence than bisection method.
- Always converges to a root.
- Does not require derivative calculation.
- Guaranteed to bracket the root throughout iterations.

**Limitations:**

- Can be slower than Newton-Raphson method.
- May converge slowly when one end of the interval remains fixed.
- Requires two initial guesses with opposite function signs.

#### False Position Code

**Code Link:** [false_pos.cpp](Solution%20of%20Non%20Linear%20Equations/False%20Position%20Method/false_pos.cpp)

#### False Position Input

**Input Format:** 

```
<degree_of_polynomial>
<coefficient_n> <coefficient_n-1> ... <coefficient_0>
<lower_bound> <upper_bound>
<max_iterations>
<tolerance>
```

**Example:**

```
2
-10 -4 1
-200 200
1
0.001
```

#### False Position Output

**Output Format:**

```
=== False Position Method ===
Equation is: <equation_representation>
Intervals containing roots: {x1,x2}  {x3,x4}
Roots are:
Root1 = <value>
Root2 = <value>
```
[↑ Back to Table of Contents](#table-of-contents)

---

### Newton Raphson Method

#### Newton Raphson Theory

The Newton–Raphson method is an iterative root-finding method that uses the function and its derivative to obtain successive approximations of a root. The method is based on the principle of linear approximation - at each iteration, the function is approximated by its tangent line, and the x-intercept of this tangent line is taken as the next approximation. Also known as Newton's method or Newton's iteration.

**Algorithm:**

    Step 1: Select an initial guess x0 close to the actual root.
    
    Step 2: Compute the next approximation using the formula:
          x1 = x0 - f(x0)/f'(x0)
    
    Step 3: Repeat until |x1-x0| or |f(x1)| is less than the given tolerance:
    
      (a) Set x0 = x1.
      (b) Check for convergence.

**Advantages:**

- Very fast convergence (quadratic convergence near the root).
- Most efficient method when derivative is easily computed.
- High accuracy with few iterations.

**Limitations:**

- Requires computation of the derivative f'(x).
- May diverge if initial guess is far from the root.
- Fails when f'(x) = 0 or is very small.
- Can oscillate or diverge for certain functions.

#### Newton Raphson Code

**Code Link:** [newton_raphson.cpp](Solution%20of%20Non%20Linear%20Equations/Newton-Raphson%20Method/newton_raphson.cpp)

#### Newton Raphson Input

**Input Format:**

```
<degree_of_polynomial>
<coefficient_n> <coefficient_n-1> ... <coefficient_0>
<lower_bound> <upper_bound>
<max_iterations>
<tolerance>
```

**Example:**

```
2
-10 -4 1
-200 200
1
0.001
```

#### Newton Raphson Output

**Output Format:**

```
=== Newton-Raphson Method ===

Equation is: <equation_representation>

Intervals containing roots: {x1}  {x2}

Roots:
Root 1 = <value>
Root 2 = <value>

```

[↑ Back to Table of Contents](#table-of-contents)

---

### Secant Method

#### Secant Theory

The secant method is a root-finding algorithm that uses a succession of roots of secant lines to better approximate a root of a function. It is a modification of the Newton-Raphson method that avoids the need to compute the derivative by approximating it using finite differences. The method requires two initial guesses but does not require them to bracket the root, making it more flexible than the false position method.

**Algorithm:**

    Step 1: Select two initial guesses x0 and x1 (preferably close to the actual root).
    
    Step 2: Compute the next approximation using the formula:
          x2 = x1 - f(x1)\*(x1-x0)/(f(x1)-f(x0))
    
    Step 3: Repeat until |x2-x1| or |f(x2)| is less than the given tolerance:
    
      (a) Set x0 = x1.
      (b) Set x1 = x2.
      (c) Compute new x2 using the formula above.
      (d) Check for convergence.

**Advantages:**

- Does not require derivative calculation.
- Faster convergence than bisection and false position methods.

**Limitations:**

- May not converge if initial guesses are poorly chosen.
- Slower than Newton-Raphson method.
- No guaranteed convergence like bracketing methods.

#### Secant Code

**Code Link:** [secant.cpp](Solution%20of%20Non%20Linear%20Equations/Secant%20Method/secant.cpp)

#### Secant Input

**Input Format:**

```
<degree_of_polynomial>
<coefficient_n> <coefficient_n-1> ... <coefficient_0>
<lower_bound> <upper_bound>
<max_iterations>
<tolerance>
```

**Example:**

```
2
-10 -4 1
-200 200
1
0.001
```

#### Secant Output

**Output Format:**

```
=== Secant Method ===
Equation is: <equation_representation>

Intervals containing roots: [x1,x2] [x3,x4]

Roots:
Root 1 = <value>
Root 2 = <value>
```
[↑ Back to Table of Contents](#table-of-contents)

---

## Solution of Interpolation Method

### Newton's Forward Interpolation

#### Forward Interpolation Theory

Newton's Forward Interpolation is a method used to estimate the value of a function at a point within a range of equally spaced data points, particularly when the required value is near the beginning of the table. This method uses forward differences to construct an interpolating polynomial.

**Algorithm:**

    Step 1: Calculate step size h = x[1] - x[0] and u = (value - x[0])/h.
    
    Step 2: Build forward difference table.
    
    Step 3: Apply Newton's Forward Interpolation formula:
          f(x) = f₀ + uΔf₀ + [u(u−1)/2!]Δ²f₀ + ... + [u(u−1)(u-2)...(u-n+1)/n!]Δⁿf₀
    
    Step 4: Compute the term using the interpolation formula.

**Advantages:**

- Works well for equally spaced data.
- Efficient for interpolation near the beginning of data.

**Limitations:**

- Requires equally spaced data points.
- Not suitable for unequally spaced data.

#### Forward Interpolation Code

**Code Link:** [forward_interpolation.cpp](Solution%20of%20Interpolation%20Methods/Newton's%20Forward%20Interpolation/Newton's%20Forward%20Interpolation/forward_interpolation.cpp)

#### Forward Interpolation Input

**Input Format:**

```
<n_data_points>
<x1> <x2> <x3> ... <xn>
<y1> <y2> <y3> ... <yn>
<x_value_to_interpolate>
```

**Example:**

```
4
3 5 7 9
180 150 120 90
4
```

#### Forward Interpolation Output

**Output Format:**

```
=== Newton's forward interpolation method ===
Number of data points: <n>
Value to interpolate: x = <value>

<difference_table>

Interpolated value at x = <value> is y = <result>
```
[↑ Back to Table of Contents](#table-of-contents)

---

### Newton's Backward Interpolation

#### Backward Interpolation Theory

Newton's Backward Interpolation is a method used to estimate the value of a function at a point within a range of equally spaced data points, particularly when the required value is near the end of the table. This method uses backward differences to construct an interpolating polynomial.

**Algorithm:**

    Step 1: Calculate step size h = x[1] - x[0] and u = (value - x[n-1])/h.
    
    Step 2: Build backward difference table.
    
    Step 3: Apply Newton's Backward Interpolation formula:
          f(x) = fₙ + vΔfₙ + [v(v+1)/2!]Δ²fₙ + ... + [v(v+1)(v+2)...(v+n-1)/n!]Δⁿfₙ
    
    Step 4: Calculate the term using the interpolation formula.

**Advantages:**

- Works well for equally spaced data.
- Efficient for interpolation near the end of data.

**Limitations:**

- Requires equally spaced data points.
- Not suitable for unequally spaced data.

#### Backward Interpolation Code

**Code Link:** [backward_interpolation.cpp](Solution%20of%20Interpolation%20Methods/Newton's%20Backward%20Interpolation/backward_interpolation.cpp)

#### Backward Interpolation Input

**Input Format:** Same as Forward Interpolation

**Example:**

```
5
24 28 32 36 40
28.06 30.19 32.75 34.94 40.00
33
```

#### Backward Interpolation Output
**Output Format:**

```
=== Newton's forward interpolation method ===
Number of data points: <n>
Value to interpolate: x = <value>

<difference_table>

Interpolated value at x = <value> is y = <result>
```
[↑ Back to Table of Contents](#table-of-contents)

---

### Newton's Divided Difference Interpolation

#### Divided Difference Interpolation Theory

Newton's Divided Difference Interpolation is a polynomial interpolation method that works with both equally and unequally spaced data points. Unlike forward and backward interpolation, this method uses divided differences instead of ordinary differences, making it versatile for any distribution of data points.

**Algorithm:**

    Step 1: Read n data points (x, y) - can be unequally spaced.
    
    Step 2: Read the value x where interpolation is required.
    
    Step 3: Build divided difference table.
    
    Step 4: Apply Newton's Divided Difference formula:
          y(x) = f[x₀] + (x-x₀)f[x₀,x₁] + (x-x₀)(x-x₁)f[x₀,x₁,x₂] + ...
    
    Step 5: Calculate the term using the interpolation formula.

**Advantages:**

- Works with both equally and unequally spaced data.
- More flexible than forward/backward interpolation.
- Suitable for any position of interpolation point.

**Limitations:**

- More complex calculations than forward/backward methods.
- May accumulate numerical errors for large datasets.

#### Divided Difference Interpolation Code

**Code Link:** [divided_interpolation.cpp](Solution%20of%20Interpolation%20Methods/Newton's%20Divided%20Difference%20Interpolation/divided_interpolation.cpp)

#### Divided Difference Interpolation Input

**Input Format:**

```
<n_data_points>
<x1> <x2> <x3> ... <xn>
<y1> <y2> <y3> ... <yn>
<x_value_to_interpolate>
<x_extra> <y_actual>  (for error calculation)
```

**Example:**

```
3
1 4 6
0 1.386294 1.79175
2
5 1.609438
```

#### Divided Difference Interpolation Output

**Output Format:**

```
=== Newton's Divided Difference Interpolation Method ===

Number of data points: <n>
Value to interpolate: x = <value>

<divided_difference_table>

Interpolated value at x = <value> is y = <result>
```
[↑ Back to Table of Contents](#table-of-contents)

---

## Solution of Numerical Differentiation

### Numerical Differentiation

#### Numerical Differentiation Theory

Numerical differentiation is the process of finding numerical approximations of derivatives of a function at a given point when the function is available only at discrete points or when analytical differentiation is difficult. It uses Newton's forward and backward differentiation formulas to estimate the derivative from tabular data without calculus.

**Algorithm:**

    Step 1: Calculate step size h = x[1] - x[0].
    
    Step 2: Build forward difference table.
    
    Step 3: Decide method based on x position:
    
    If x is near the beginning:
      Use Newton's Forward Differentiation:
        (a) Calculate u = (x - x[0])/h
        (b) y' = [Δf₀ + (2u−1)Δ²f₀/2 + (3u²-6u+2)Δ³f₀/6] / h
     Else (x is near the end):
      Use Newton's Backward Differentiation:
        (a) Calculate v = (x - x[n-1])/h
        (b) y' = [Δf₀ + (2v+1)Δ²f₀/2 + (3v²+6v+2)Δ³f₀/6] / h
    
    Step 4: Output the derivative value.

**Advantages:**

- Useful when analytical differentiation is impossible.
- Works well with tabulated experimental data.
- Can handle equally spaced data points efficiently.

**Limitations:**

- Requires equally spaced data points.
- Accuracy decreases with larger step size h.
- Sensitive to errors in data values.
- Higher order derivatives have increasing errors.

#### Numerical Differentiation Code

**Code Link:** [differentiation.cpp](Solution%20of%20Numerical%20Differentiation/differentiation.cpp)

#### Numerical Differentiation Input

**Input Format:**

```
<n_data_points>
<x1> <x2> <x3> ... <xn>
<y1> <y2> <y3> ... <yn>
<x_value_for_derivative>
```

**Example Input:**

```
5
0 1 2 3 4 
0 1 8 27 64
1.0
```
#### Numerical Differentiation Output
**Output Format:**

```
Using Newton's Forward/Backward Differentiation:
First derivative at x = <value> is <result>
```
[↑ Back to Table of Contents](#table-of-contents)

---


## Solution of Linear Equations

### Gauss Elimination Method

#### Gauss Elimination Theory
 
The Gauss elimination method is a systematic technique for solving a system of linear equations. It reduces the system to an **upper triangular form** using the **forward elimination** approach and then finds the values of unknowns using **back substitution**. The method consists of two main phases:

1. **Forward elimination phase:**  
   Manipulates the equations to eliminate some unknowns and produce an upper triangular system.

2. **Back substitution phase:**  
   Solves the equations starting from the last equation of the upper triangular system.

**Algorithm:**

1. Form the augmented matrix of the given system of linear equations.  
2. Arrange the equations so that the coefficient of the first unknown in the first equation is non-zero. If necessary, interchange equations.  
3. If no such row exists, the system is singular.  
4. Divide the first equation by this coefficient to make the coefficient of the first unknown equal to one.  
5. Using the first equation, eliminate the first unknown from all other equations.  
6. Repeat the above process for the second, third, and subsequent unknowns until the system is reduced to an upper triangular form.  
7. **Solution type check:**  
   - If at any stage a row has all zero coefficients but a non-zero constant term, the system has **no solution**.  
   - If at least one row has all zero coefficients and a zero constant term, the system has **infinitely many solutions**.  
   - Otherwise, the system has a **unique solution**.  
8. If a unique solution exists, solve the last equation to obtain the last unknown.  
9. Use **back substitution** to find the remaining unknowns.

**Advantages:**  
- Systematic and straightforward for small to medium systems  
- Can determine if a system has a unique solution, no solution, or infinitely many solutions  
- Works well for hand calculations and can be implemented in a program  
- Useful as a basis for more advanced methods like LU decomposition  

**Disadvantages:**  
- Computationally expensive for very large systems  
- Sensitive to rounding errors, which can lead to inaccurate results  
- Not efficient for sparse matrices without modifications  
- Pivoting may be necessary to avoid division by very small numbers


#### Gauss Elimination Code

**Code Link:** [Gauss Elimination.cpp](https://github.com/naurina-haque/Numerical-Methods-Console-App/blob/main/Solution%20of%20Linear%20Equations/Gauss%20Elimination/Gauss%20Elimination.cpp)

#### Gauss Elimination Input

**Input Format:**

```
n
a₁₁ a₁₂ a₁₃ … a₁ₙ b₁
a₂₁ a₂₂ a₂₃ … a₂ₙ b₂
…
aₙ₁ aₙ₂ aₙ₃ … aₙₙ bₙ

```
**Explanation:**

n = number of equations  

aᵢⱼ = coefficients of the system

bᵢ = constant term in the i-th equation

**Example:**
```
3
2 3 -1 5
4 1 2 6
-2 5 3 12

```

#### Gauss Elimination Output


**Output Format:**

```
---Gauss Elimination Method---
Upper Triangular Matrix:
u₁₁ u₁₂ u₁₃ … u₁ₙ b₁
0   u₂₂ u₂₃ … u₂ₙ b₂
0   0   u₃₃ … u₃ₙ b₃
…   …   …       … …
0   0   0   … uₙₙ bₙ

Solution Vector :
x₁   
x₂   
x₃   
…  
xₙ 

```

**Example:**
```
---Gauss Elimination Method---
Upper Triangular Matrix:
2 1 -1 3 2 9 
0 2.5 2.5 -2.5 0 3.5 
0 0 5 -3 -5 5.8 
0 0 0 1.4 3 3.36 
0 0 0 0 1.86 2.2 
x1= 5.15
x2= -1
x3= 2.26
x4= -0.138
x5= 1.18

```




[↑ Back to Table of Contents](#table-of-contents)

---

### Gauss Jordan Elimination Method

#### Gauss Jordan Theory

# Gauss-Jordan Method

**Theory:**  
The Gauss-Jordan method is a popular technique for solving a system of linear equations. Unlike Gauss elimination, which eliminates variables only from rows below the pivot, the Gauss-Jordan method eliminates variables from **all other rows** (both above and below the pivot). This results in a **diagonal (identity) matrix** for the coefficient part of the augmented matrix.  
All rows are then normalized by dividing by their pivot elements. The method requires approximately **50% more arithmetic operations** than Gauss elimination, which is why it is less commonly used for large systems.

**Algorithm:**

    1. Form the augmented matrix of the given system of linear equations.  
    2. Choose the first pivot element.  
    3. If the pivot is zero, interchange the row with a lower row having a non-zero element in the same column.  
    4. If no such row exists, the system is singular.  
    5. Normalize the pivot row by dividing the entire row by the pivot element, so that the pivot becomes 1.  
    6. Using the normalized pivot row, eliminate the corresponding variable from all other rows (both above and below the pivot).  
    7. Move to the next pivot position and repeat Steps 2–6 until the coefficient matrix becomes a diagonal (identity) matrix.  
    8. Solution type check:  
       - If a row has all zero coefficients but a non-zero constant, the system has no solution.  
       - If a row has all zero coefficients and a zero constant, the system has infinitely many solutions.  
       - Otherwise, the system has a unique solution.  
    9. If a unique solution exists, the right-hand column of the final augmented matrix gives the solution vector directly.

**Advantages:**  
- Produces the solution vector directly without back substitution  
- Can determine if a system has a unique solution, no solution, or infinitely many solutions  
- Systematic and straightforward for small to medium systems  
- Works well as a conceptual or educational tool  

**Disadvantages:**  
- Requires more arithmetic operations than Gauss elimination (~50% more)  
- Sensitive to rounding errors, which can affect accuracy  
- Less efficient for large systems  
- Pivoting may be necessary to avoid division by very small numbers


#### Gauss Jordan Code

**Code Link:** [Gauss Jordan elimination.cpp](https://github.com/naurina-haque/Numerical-Methods-Console-App/blob/main/Solution%20of%20Linear%20Equations/Gauss%20Jordan%20Elimination/Gauss%20Jordan%20elimination.cpp)

#### Gauss Jordan Input

**Input Format:**

```
n
a₁₁ a₁₂ a₁₃ … a₁ₙ b₁
a₂₁ a₂₂ a₂₃ … a₂ₙ b₂
…
aₙ₁ aₙ₂ aₙ₃ … aₙₙ bₙ

```
**Explanation:**

n = number of equations  

aᵢⱼ = coefficients of the system

bᵢ = constant term in the i-th equation

**Example:**
```
3
2 3 -1 5
4 1 2 6
-2 5 3 12

```


#### Gauss Jordan Output

**Output Format:**

```
---Gauss-Jordan Method---
Upper Triangular Matrix:
u₁₁ u₁₂ u₁₃ … u₁ₙ b₁
0   u₂₂ u₂₃ … u₂ₙ b₂
0   0   u₃₃ … u₃ₙ b₃
…   …   …       … …
0   0   0   … uₙₙ bₙ

Row-Reduced Echelon Form:
1 0 0 … 0 b₁
0 1 0 … 0 b₂
0 0 1 … 0 b₃
… … …     … …
0 0 0 … 1 bₙ

Solution Vector :
x₁ = b₁  
x₂ = b₂  
x₃ = b₃  
…  
xₙ = bₙ

```

**Example:**

```
---Gauss Jordan Method---
Upper Triangular Matrix:
2 1 -1 3 2 9 
0 2.5 2.5 -2.5 0 3.5 
0 0 5 -3 -5 5.8 
0 0 0 1.4 3 3.36 
0 0 0 0 1.86 2.2 

Row Reduced Echelon form:
1 0 0 0 0 5.15 
0 1 0 0 0 -1 
0 0 1 0 0 2.26 
0 0 0 1 0 -0.138 
0 0 0 0 1 1.18 

x1= 5.15
x2= -1
x3= 2.26
x4= -0.138
x5= 1.18

```


[↑ Back to Table of Contents](#table-of-contents)

---

### LU Decomposition Method

#### LU Decomposition Theory

*Also Known As:*  
- LU Factorization Method  
- Crout’s Method  
- Cholesky Method  
- Do little’s Method  

In LU decomposition, **L** is a lower triangular matrix and **U** is an upper triangular matrix, such that **A = LU**.

**Algorithm:** 

    1. Initialize L as an identity matrix and U as a copy of the given matrix A.  
    2. For each pivot element, eliminate the elements below it in U by computing multipliers and storing them in L.  
    3. Use each multiplier to subtract a suitable multiple of the pivot row from the rows below so that the elements under the pivot become zero.  
    4. If any pivot becomes zero and cannot be swapped, the matrix is singular.  
    5. After decomposition, U is upper triangular, L is lower triangular with 1s on the diagonal, and A = LU.  
    6. To solve AX = B, solve LY = B by forward substitution.  
    7. Solve UX = Y by back substitution to obtain the solution vector.

**Advantages:**  
- Reduces computational effort when solving multiple systems with the same coefficient matrix but different right-hand sides.  
- Systematic and easy to implement for small to medium matrices.  
- Helps in understanding matrix factorization and is foundational for advanced methods.  
- Works efficiently for large, well-conditioned matrices.  

**Disadvantages:**  
- Requires pivoting in many cases to avoid division by zero or small numbers (numerical instability).  
- Not suitable for singular or nearly singular matrices.  
- Slightly more complex to implement than simple Gauss elimination.  
- Less efficient if only a single system needs to be solved (compared to Gauss elimination).


#### LU Decomposition Code


**Code Link:** [LU Decomposition.cpp](https://github.com/naurina-haque/Numerical-Methods-Console-App/blob/main/Solution%20of%20Linear%20Equations/LU%20Decomposition/LU%20Decomposition.cpp)

#### LU Decomposition Input

**Input Format:**

```
n
a₁₁ a₁₂ a₁₃ … a₁ₙ b₁
a₂₁ a₂₂ a₂₃ … a₂ₙ b₂
…
aₙ₁ aₙ₂ aₙ₃ … aₙₙ bₙ

```
**Explanation:**

n = number of equations  

aᵢⱼ = coefficients of the system

bᵢ = constant term in the i-th equation

**Example:**
```
3
2 3 -1 5
4 1 2 6
-2 5 3 12

```


#### LU Decomposition Output

**Output Format:**

```
---LU Decomposition Method---

Lower Triangular Matrix:
l₁₁ l₁₂ l₁₃ …
l₂₁ l₂₂ l₂₃ …
…
lₙ₁ lₙ₂ lₙ₃ …

Upper Triangular Matrix:
u₁₁ u₁₂ u₁₃ …
u₂₁ u₂₂ u₂₃ …
…
uₙ₁ uₙ₂ uₙ₃ …

System has Unique Solution

Value of Y :
y₁ y₂ y₃ … yₙ

Value of X :
x₁ x₂ x₃ … xₙ

```
**Example:**

```
---LU Decomposition Method---

Lower Triangular Matrix (L):
1 0 0
2 1 0
-1 -1.6 1

Upper Triangular Matrix (U):
2 3 -1
0 -5 4
0 0 8.4

System has Unique Solution

Value of Y:
y₁=5 y₂=-4 y₃=10.6

Value of X:
x₁=0.417 x₂=1.81 x₃=1.26

```

[↑ Back to Table of Contents](#table-of-contents)

---


### Matrix Inversion

#### Matrix Inversion Theory

Matrix Inversion Method solves a system of linear equations by finding the inverse of the coefficient matrix. Once the inverse is obtained, the solution vector is found by multiplying the inverse matrix with the constant vector: X = A⁻¹B.

**Algorithm:**

    Step 1: Create an augmented matrix [A | I] where I is the identity matrix.
    
    Step 2: Apply row operations to transform A into I.
    
    Step 3: The resulting matrix [I | A⁻¹] contains the inverse.
    
    Step 4: Multiply A⁻¹ with B to get the solution X.

**Advantages:**

- Once inverse is found, can solve multiple systems quickly.
- Useful when matrix inverse is needed for other purposes.

**Limitations:**

- Computationally expensive for large matrices.
- Not all matrices have inverses.
- Numerically unstable for ill-conditioned matrices.

#### Matrix Inversion Code

**Code Link:** [inversion.cpp](Solution%20of%20Linear%20Equations/Matrix%20Inversion%20Method/inversion.cpp)

#### Matrix Inversion Input

**Input Format:** Similar to LU Decomposition

**Example:**

```
Enter number of eqn: 3
Enter augmented Matrix:
2 3 -1 5
4 1 2 6
-2 5 3 12
```

#### Matrix Inversion Output

**Output Format:**

```
Inverse Matrix:
<inverse_matrix>

Solution:
x1 = <value>
x2 = <value>
x3 = <value>
```
[↑ Back to Table of Contents](#table-of-contents)

---


## Solution of Numerical Integration

### Simpson's 1/3rd Rule

#### Simpson's 1/3rd Theory

Newton–Cotes methods are a family of numerical integration formulas based on replacing a function with a polynomial that passes through evenly spaced points. Polynomials are used because they are simple to integrate. There are two types of Newton–Cotes formulas:  

- **Closed form:** endpoints included (used for definite integrals)  
- **Open form:** endpoints not included (rarely used for definite integrals)  

Simpson’s 1/3rd Rule is a **Closed Newton-Cotes formula**. It uses **3 equally spaced points** and approximates the curve with a **second-degree (quadratic) polynomial**. The formula works best when the function is smooth, and the interval count is even.

**Formula:**  

    ∫ₐᵇ y dx = h/3 [ (y₀ + yₙ) + 4(y₁ + y₃ + y₅ + … + yₙ₋₁) + 2(y₂ + y₄ + y₆ + … + yₙ₋₂) ]

Where:

    - a = lower limit  
    - b = upper limit  
    - n = number of equal parts (**even**)  
    - h = (b-a)/n = interval width  
    - yᵢ = f(xᵢ)  

**Algorithm:**  

    1. Divide the interval [a,b] into an **even number** of subintervals n, each of width h = (b-a)/n.  
    2. Calculate the values of the function at equally spaced points:  
                x₀ = a,  x₁ = a+h,  x₂ = a+2h, …, xₙ = b  
    3. Apply Simpson’s 1/3 formula:  
               ∫ₐᵇ y dx = h/3 [(y₀ + yₙ) + 4(y₁ + y₃ + y₅ + … + yₙ₋₁) + 2(y₂ + y₄ + y₆ + … + yₙ₋₂) ]  
    4. Compute the summation and obtain the approximate value of the integral.

**Advantages:**  
- Gives higher accuracy than the Trapezoidal rule  
- Exact for all polynomials up to degree two  
- Simple to apply when data points are equally spaced  
- Widely used in engineering and scientific computations

**Disadvantages:**  
- Requires an **even number** of subintervals  
- Cannot be applied if data points are unequally spaced  
- Less accurate for functions with **sharp curvature or discontinuities**  
- More computational effort compared to the Trapezoidal rule


#### Simpson's 1/3rd Code

**Code Link:** [Simpson's 1_3rd.cpp](https://github.com/naurina-haque/Numerical-Methods-Console-App/blob/main/Solution%20of%20Numerical%20Integration/Simpson's%201_3%20Rule/Simpson's%201_3rd.cpp)

#### Simpson's 1/3rd Input


**Input Format:**
```
deg → degree of the polynomial  
a₍0₎, a₍1₎, …, a₍deg₎` → coefficients from x^deg down to the constant term  
b → upper limit of integration  
a → lower limit of integration  
n → number of subintervals (must be even number for Simpson’s 1/3rd Rule)
```

**Example:**
```
5
1 4 0 0 0 1
5
0 
9
```

#### Simpson's 1/3rd Output

**Output Format:**
```
print the function
<approx_integral> → value computed using Simpson’s 1/3rd rule  
<exact_integral> → exact analytical value of the integral  
<relative_error> → |(Exact - Approx) / Exact|
```

**Example:**
```
f(x)=1x^5+4x^4+1
Simpson's 1/3 Result: 5109.85417
Exact Integral: 5109.16667
Relative Error: 0.00013

```

[↑ Back to Table of Contents](#table-of-contents)

---

### Simpson's 3/8th Rule

# Simpson’s 3/8th Rule

#### Simpson's 3/8th Theory

Simpson’s 3/8th Rule is a **Closed Newton-Cotes formula**. It uses **4 equally spaced points** and approximates the curve with a **third-degree (cubic) polynomial**. The formula works best when the function is smooth, and the interval count is a **multiple of 3**.

**Formula:**  

    ∫ₐᵇ y dx = 3h/8 [ (y₀ + yₙ) + 3(y₁ + y₂ + y₄ + y₅ + … + yₙ₋₁) + 2(y₃ + y₆ + y₉ + … + yₙ₋₃) ]

Where:

    - a = lower limit  
    - b = upper limit  
    - n = number of equal parts (**multiple of 3**)  
    - h = (b-a)/n = interval width  
    - yᵢ = f(xᵢ)  

**Algorithm:** 

    1. Divide the interval [a, b] into **n subintervals**, where n is a multiple of 3, each of width h = (b-a)/n.  
    2. Calculate the function values at equally spaced points:  
          x₀ = a,  x₁ = a+h,  x₂ = a+2h, …, xₙ = b  
    3. Apply Simpson’s 3/8 formula:  
          ∫ₐᵇ y dx = 3h/8 [ (y₀ + yₙ) + 3(y₁ + y₂ + y₄ + y₅ + … + yₙ₋₁) + 2(y₃ + y₆ + y₉ + … + yₙ₋₃) ]  
    4. Compute the summation to obtain the approximate value of the integral.

**Advantages:**  
- More accurate than the Trapezoidal rule for smooth functions  
- Exact for all polynomials up to **degree three**  
- Suitable when the number of subintervals is a multiple of 3  
- Useful for integrating functions with moderate curvature

**Disadvantages:**  
- Requires the number of subintervals to be a multiple of 3  
- Cannot be applied if data points are unequally spaced  
- Slightly more complex and computationally expensive than Simpson’s 1/3 rule  
- Not efficient for functions with sharp discontinuities

#### Simpson's 3/8th Code

**Code Link:** [Simpson's 3_8th.cpp](https://github.com/naurina-haque/Numerical-Methods-Console-App/blob/main/Solution%20of%20Numerical%20Integration/Simpson's%203_8%20Rule/Simpson's%203_8th.cpp)

#### Simpson's 3/8th Input

**Input Format:**
```
deg → degree of the polynomial  
a₍0₎, a₍1₎, …, a₍deg₎` → coefficients from x^deg down to the constant term  
b → upper limit of integration  
a → lower limit of integration  
n → number of subintervals (must be multiple of 3 for Simpson’s 3/8th Rule)
```

**Example:**
```
5
1 4 0 0 0 1
5
0 
9
```

#### Simpson's 3/8th Output

**Output Format:**
```
print the function
<approx_integral> → value computed using Simpson’s 3/8th rule  
<exact_integral> → exact analytical value of the integral  
<relative_error> → |(Exact - Approx) / Exact|  

```

**Example:**
```

f(x)=1x^5+4x^4+1
Simpson's 3/8th Result: 5111.52435
Exact Integral: 5109.16667
Relative Error: 0.00046
```

[↑ Back to Table of Contents](#table-of-contents)

---

## Regression Methods

### Linear Regression

#### Linear Regression Theory

Linear regression is a statistical method used to model the relationship between a dependent variable `y` and an independent variable `x` by fitting a straight line through the data points. The goal is to find the best-fitting line that minimizes the difference between the actual data points and the predicted values on the line. This line is represented by the equation: 

                    y = a + b*x
                    
where `a` is the y-intercept and `b` is the slope of the line. The coefficients `a` and `b` are determined using the **least squares method**, which minimizes the sum of the squares of the vertical distances between the observed values and the line. Linear regression is widely used in data analysis, forecasting, and modeling relationships that are approximately linear. It provides a simple and effective way to predict future values based on existing data.

**Algorithm:**

    1. Read the data points from input.  
    2. Compute the required summations:  
                 - Σxᵢ, Σyᵢ, Σxi², Σxᵢ*yᵢ  
    3. Check if the denominator for calculating `b` is zero. If zero, report an error (cannot compute slope).  
    4. Compute the slope `b` and intercept `a`:
                 b = ( n* Σ(xᵢyᵢ) - ΣxᵢΣyᵢ ) / ( n * Σ(xᵢ²) - (Σxᵢ)² )
                 a = (Σyᵢ - b * Σxᵢ)/n
    5. Print the regression equation
    6. Interpolate or predict `y` for a given `x`, if required.
    
**Advantages:**  
- Simple to understand and implement.  
- Fast computation.  
- Works well if the relationship is nearly linear.

**Disadvantages:**  
- Cannot model nonlinear relationships.  
- Sensitive to outliers.
      
#### Linear Regression Code

**Code Link:** [Linear Regression.cpp](https://github.com/naurina-haque/Numerical-Methods-Console-App/blob/main/Regression%20Methods/Linear%20Regression/Linear%20Regression.cpp)

#### Linear Regression Input


**Input Format:**
```
n → total number of points  
xᵢ yᵢ → coordinates of each data point 
```

**Example:**
```
5
1 2
2 3
3 5
4 4
5 6
```

#### Linear Regression Output

**Output Format:**
```
Linear Regression Equation:
y = a + b x
```
Explanation:
 -`a` → intercept of the regression line  
 -`b` → slope of the regression line

**Example:**
```
Linear Regression Equation:
y = 1.300000 + 0.900000x
```

[↑ Back to Table of Contents](#table-of-contents)

---

### Exponential Regression

#### Exponential Regression Theory

Exponential regression models data that grows or decays exponentially. The relationship between the dependent variable `y` and independent variable `x` is given by:

             y = a * x^b

where `a` and `b` are constants. This is useful for data that follows a nonlinear trend increasing or decreasing at a variable rate. By taking the natural logarithm of both `x` and `y`, it can be transformed into a linear regression problem:

           ln(y) = ln(a) + b * ln(x)


This allows us to compute `ln(a)` and `b` using least squares, then exponentiate to find `a`.

**Algorithm :**

    1. Read the data points `(xᵢ, yᵢ)`.  
    2. Check that all `xᵢ > 0` and `yᵢ > 0` (required for logarithm).  
    3. Transform the data: `Xᵢ = ln(xᵢ)`, `Yᵢ = ln(yᵢ)`.  
    4. Apply linear regression on `(Xᵢ, Yᵢ)` to compute slope `b` and intercept `ln(a)`.  
    5. Compute `a = e^(intercept)`.  
    6. Print the regression equation: `y = a * xᵇ`.  
    7. Predict `y` for a given `x` if needed.


**Advantages:**  
- Can model nonlinear relationships.  
- Simple transformation reduces it to linear regression.  

**Disadvantages:**  
- Requires positive `x` and `y` values.  
- Sensitive to outliers and noise.


#### Exponential Regression Code

**Code Link:** [Exponential Regression.cpp](https://github.com/naurina-haque/Numerical-Methods-Console-App/blob/main/Regression%20Methods/Exponential%20Regression/Exponential%20Regression.cpp)

#### Exponential Regression Input


**Input Format:**
```
n → total number of points  
xᵢ yᵢ → coordinates of each data point 
```

**Example:**
```
5 
1 2
2 3
3 5
4 4
5 6

```

#### Exponential Regression Output

**Output Format:**

```
Exponential Regression Equation:
y = a * x^b

```
Explanation:
 -`a` → base coefficient  
 -`b` → exponent coefficient 

**Example:**

```
Exponential Regression Equation:
y = 2.017931 * x^0.641022
```

[↑ Back to Table of Contents](#table-of-contents)

---

### Polynomial Regression

#### Polynomial Regression Theory

Polynomial regression models the relationship between `y` and `x` using a polynomial of degree `n`:

       y = a₀ + a₁x + a₂x² + ... + aₙxⁿ

where `a₀, a₁, ..., aₙ` are coefficients. It is useful for capturing nonlinear trends in data. The coefficients are determined using the **least squares method** by solving a system of normal equations.

**Algorithm :**

    1. Read the data points `(xᵢ, yᵢ)`.  
    2. Choose the degree `n` of the polynomial.  
    3. Compute the required summations: Σxᵢ, Σxᵢ², ..., Σxᵢ²ⁿ and Σyᵢ, Σxᵢyᵢ, ..., Σxᵢⁿyᵢ.  
    4. Set up and solve the normal equations to find coefficients `a₀, a₁, ..., aₙ`.  
    5. Print the regression equation
    6. Predict `y` for given `x` values if needed.

**Advantages:**  
- Can model complex nonlinear relationships.  
- Flexible and fits data more accurately than linear regression.

**Disadvantages:**  
- Overfitting if degree `n` is too high.  
- Computationally more expensive.  
- Sensitive to outliers.


#### Polynomial Regression Code

**Code Link:** [Polynomial Regression.cpp](https://github.com/naurina-haque/Numerical-Methods-Console-App/blob/main/Regression%20Methods/Polynomial%20Regression/Polynomial%20Regression.cpp)

#### Polynomial Regression Input


**Input Format:**

```

```

**Example:**

```
5 2
1 2
2 3
3 5
4 4
5 6

```

#### Polynomial Regression Output

**Output Format:**

```
Polynomial Regression Equation:
y = c₀ + c₁x + c₂x^2 + … + cₘ*x^m

```
Explanation:

- `c₀, c₁, …, cₘ` → coefficients of the polynomial

**Example:**

```
Polynomial Regression Equation:
y = 0.800000 + 1.328571*x - 0.071429*x^2

``` 

[↑ Back to Table of Contents](#table-of-contents)

---

## Solution of Ordinary Differential Equations

### Runge-Kutta Method

#### Runge-Kutta Theory
  
The Runge-Kutta (RK) method is a family of iterative techniques used to approximate solutions of ordinary differential equations (ODEs). The **4th-order Runge-Kutta method (RK4)** is the most commonly used and provides a good balance between **accuracy** and **computational efficiency**.  

RK4 is an *initial value problem method*, as the values x₀ and y₀ are given. The method computes the value of y at xₙ₊₁ = xₙ + h by taking a weighted average of four slopes:  

- Slope at the beginning of the interval  
- Two slopes at the midpoint  
- Slope at the end of the interval  

This weighted averaging improves accuracy significantly compared to **Euler’s** and **RK2** methods.

**Formula:**  
For a first-order differential equation dy/dx = f(x, y), the solution at xₙ₊₁ = xₙ + h is obtained using:

    - k₁ = h * f(xₙ, yₙ)  
    - k₂ = h * f(xₙ + h/2, yₙ + k₁/2)  
    - k₃ = h * f(xₙ + h/2, yₙ + k₂/2)  
    - k₄ = h * f(xₙ + h, yₙ + k₃)  

Next value of y:  

yₙ₊₁ = yₙ + 1/6 * (k₁ + 2k₂ + 2k₃ + k₄)

**Algorithm:**  

    1. Read the initial values x₀, y₀, step size h, and final value xₙ.  
    2. Define the differential equation f(x, y).  
    3. Compute k₁, k₂, k₃, and k₄ using the RK4 formulas.  
    4. Calculate the next approximation yₙ₊₁.  
    5. Update x = x + h and repeat until x = xₙ.

**Advantages:**  
- High accuracy compared to Euler and RK2 methods  
- Does not require higher-order derivatives  
- Stable and reliable for many engineering and scientific problems  
- Simple to implement computationally  

**Disadvantages:**  
- Requires more computations per step than Euler’s method  
- Not self-correcting; smaller step size needed for stiff equations  
- Computationally expensive for very large systems


#### Runge-Kutta Code

**Code Link:** [Runge-Kutta.cpp](https://github.com/naurina-haque/Numerical-Methods-Console-App/blob/main/Solution%20of%20Ordinary%20Differential%20Equation/Runge-Kutta%20Method/Runge-Kutta.cpp)

#### Runge-Kutta Input


**Input Format:**
```
 x₀ → initial x-value  
 y₀ → initial y-value  
 h  → step size  
 xₙ → final x-value

```

**Example:**
```
0
1
0.1
0.5
```

#### Runge-Kutta Output


**Output Format:**
```
---Runge-Kutta Method---
x₀ = value₀, y₀ = value₀
x₁ = value₁, y₁ = value₁
x₂ = value₂, y₂ = value₂
...
xₙ = valueₙ, yₙ = valueₙ
```

**Example:**
```
---Runge-Kutta Method---
x1 = 0.000000   y1 = 1.000000
x2 = 0.100000   y2 = 1.115512
x3 = 0.200000   y3 = 1.264208
x4 = 0.300000   y4 = 1.449575
x5 = 0.400000   y5 = 1.675473
x6 = 0.500000   y6 = 1.946162
```

[↑ Back to Table of Contents](#table-of-contents)

---








