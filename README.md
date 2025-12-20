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

#### Gauss Elimination Code

#### Gauss Elimination Input

#### Gauss Elimination Output

[↑ Back to Table of Contents](#table-of-contents)
---

### Gauss Jordan Elimination Method

#### Gauss Jordan Theory

#### Gauss Jordan Code

#### Gauss Jordan Input

#### Gauss Jordan Output

[↑ Back to Table of Contents](#table-of-contents)
---

### LU Decomposition Method

#### LU Decomposition Theory

#### LU Decomposition Code

#### LU Decomposition Input

#### LU Decomposition Output

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

#### Simpson's 1/3rd Code

#### Simpson's 1/3rd Input

#### Simpson's 1/3rd Output

[↑ Back to Table of Contents](#table-of-contents)

---

### Simpson's 3/8th Rule

#### Simpson's 3/8th Theory

#### Simpson's 3/8th Code

#### Simpson's 3/8th Input

#### Simpson's 3/8th Output

[↑ Back to Table of Contents](#table-of-contents)

---

## Regression Methods

### Linear Regression

#### Linear Regression Theory

#### Linear Regression Code

#### Linear Regression Input

#### Linear Regression Output

[↑ Back to Table of Contents](#table-of-contents)

---

### Exponential Regression

#### Exponential Regression Theory

#### Exponential Regression Code

#### Exponential Regression Input

#### Exponential Regression Output

[↑ Back to Table of Contents](#table-of-contents)

---

### Polynomial Regression

#### Polynomial Regression Theory

#### Polynomial Regression Code

#### Polynomial Regression Input

#### Polynomial Regression Output

[↑ Back to Table of Contents](#table-of-contents)

---

## Solution of Ordinary Differential Equations

### Runge-Kutta Method

#### Runge-Kutta Theory

#### Runge-Kutta Code

#### Runge-Kutta Input

#### Runge-Kutta Output

[↑ Back to Table of Contents](#table-of-contents)

---








