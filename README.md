# CPP_02



## Understanding and Using Floating Point Numbers


In reality, a 4-byte floating point number, for example, can actually hold fewer distinct values than a 4-byte integer. The reason for this is, of course, that the internal representation of floating point numbers is not straightforward. Bits representing an integer are interpreted literally as a binary number, while bits in a floating point number have a more complicated interpretation.


### Accuracy vs. Precision
Accuracy and precision are two concepts in measurement that nicely capture the different properties of ints and floats. 

"Accuracy" refers to **how close a measurement is to the true value**, whereas "precision" has to do with **how much information you have about a quantity**, how uniquely you have it pinned down.

**Integer arithmetic** enjoys the property of **complete accuracy**, However,  **lack precision**. 

if I have the integer "2", it is exactly 2, on the dot, and nobody can dispute that. Furthermore, if I add 1 to it, I know I will get exactly 3. Whatever operations I do with integers, provided there is no overflow, I will always get a number that matches the correct answer bit-for-bit. 

Dividing both 5 and 4 by 2, for instance, will both yield 2. Integers are **unable to keep track of the fractional part**, so the information that I had a slightly bigger number than 4 (namely, 5) is lost in the process. Integers are too "chunky" to represent these finer gradations;

We can not make a perfect sphere wiht bricks (integers).

Floating point numbers are the exact opposite of integers with respect to accuracy and precision. 

Floating point numbers have **good precision**, But floating point numbers have **poor accuracy**

Floating point numbers never deliberately discard information representing your numbers. If you had enough bits, you could reverse any FP calculation to get the original number, just like how, with enough bits, you could represent an arbitrarily large integer. 

But floating point numbers have poor accuracy. If ints are like bricks, then floats might be thought of as silly putty. You have enough control to mold them into complex curved shapes, but they leave something to be desired when it comes to forming a specified target shape. Imagine trying to make a perfect cube out of silly putty—you'll never get those corners as sharp as they should be. In fact, in many cases there is literally no hope of a floating point answer's matching the correct answer bit for bit.

Now how can I make an outlandish claim like that? Floating point numbers are inherently different from integers in that not every fraction can be represented exactly in binary, whereas any integer can. Binary arithmetic is not to blame; the same restriction applies in any base system. Consider the number 1/3. No finite decimal digit representation (e.g. 0.333333) can ever be equal to 1/3; we can never have enough 3's. Thus it is more than likely that the computed result you need cannot be represented accurately by a finite floating point variable—you're going to be wrong by at least a little bit no matter what you do. We know that floats are still useful, though; 

We just have to prevent those little roundoff errors from stepping on our toes. 

## Floating point number representation

The most common representation is the IEEE-754 standard.

An IEEE-754 float (4 bytes) or double (8 bytes) has three components (there is also an analogous 96-bit extended-precision format under IEEE-854): a sign bit telling whether the number is positive or negative, an exponent giving its order of magnitude, and a mantissa specifying the actual digits of the number. Using single-precision floats as an example, here is the bit layout:

|Nunmber| seeeeeeeemmmmmmmmmmmmmmmmmmmmmmm|
|-------|---------------------------------|
|bit #  |  3         2         1         0|
|bit #  | 10987654321098765432109876543210|
|meaning| s                         <sign>|
|meaning|  eeeeeeee             <exponent>|
|       |  12345678                       |
|meaning|<mantisa> mmmmmmmmmmmmmmmmmmmmmmm|
|       |          12345678901234567890123|
|       |                   1         2   | 

The value of the number is the mantissa times 2^x, where x is the exponent. 

Notice that we are dealing with binary fractions, so that 0.1 (the leftmost mantissa bit) means 1/2 (the place values to the right of the decimal point are 2^-1, 2^-2, etc., just as we have 10^-1, 10^-2, etc. in decimal).

Notice further that there's a potential problem with storing both a mantissa and an exponent: 2x10^-1 = 0.2x10^0 = 0.02x10^1 and so on. 

 
This problem is circumvented wiht "1.m" representation, by interpreting the whole mantissa as being to the right of the decimal point, with an **implied "1"** always present to the left of the decimal. 

### Special cases

#### Zero
The good people at the IEEE standards committee solve this by making zero a special case: if every bit is zero (the sign bit being irrelevant), then the number is considered zero.

I'll refer to this as a "1.m" representation. "But wait!" you cry. "What if I don't want a 1 there?" Think of it is as follows: imagine writing a real number in binary. Unless it's zero, it's gotta have a 1 somewhere. Shift your decimal point to just after the first 1, then don't bother to store that 1 since we know it's always implied to be there. Now all you have to do is set the exponent correctly to reproduce the original quantity.

#### One

The way out of this is that the interpretation of the exponent bits is not straightforward either.

To represent humble 1.0, which would have to be 1.0x2^0 (an exponent of zero, times the implied one)

The exponent of a single-precision float is "shift-127" encoded, meaning that **the actual exponent is eeeeeeee minus 127**. 

we can get an exponent of zero by storing 127 (0x7f). 

The low extreme of the spectrum of representable magnitudes, which should be 2^-127. 
Due to shift-127, the lowest possible exponent is actually -126 (1 - 127).

It seems wise, to give up the smallest exponent instead of giving up the ability to represent 1 or zero!

#### +/- infinity
if every bit of the exponent is set (yep, we lose another one)The sign bit still distinguishes +/-inf.

#### +/- NaN

if every bit of the exponent is set plus any mantissa bits are set. The sign bit still distinguishes +/-NaN.

|Nunmber|  <code style="color : red">s</code><code style="color : green">eeeeeeees</code><code style="color : blue">mmmmmmmmmmmmmmmmmmmmmmm</code>|
|-------|----------------------------------|
|bit #  |   3         2         1         0|
|bit #  |  10987654321098765432109876543210|
|meaning|  s                         <sign>|
|meaning|   eeeeeeee             <exponent>|
|       |   12345678                       |
|meaning|<mantisa>  mmmmmmmmmmmmmmmmmmmmmmm|
|       |           12345678901234567890123|
|       |                    1         2   |
|0      |0x00000000                        |
|0      |   <code style="color : red">0</code> <code style="color : green">00000000</code> <code style="color : blue">0000000000000000000000</code>|
|1.0    |0x3f800000                        |
|1.0    |   <code style="color : red">0</code> <code style="color : green">01111111</code> <code style="color : blue">0000000000000000000000</code>|
|0.5    |0x3f000000                        |
|0.5    |   <code style="color : red">0</code> <code style="color : green">01111110</code> <code style="color : blue">0000000000000000000000</code>|
|3      |0x40400000                        |
|3      |   <code style="color : red">0</code> <code style="color : green">10000000</code> <code style="color : blue">1000000000000000000000</code>|
|+inf   |0x7f800000                        |
|+inf   |   <code style="color : red">0</code> <code style="color : green">11111111</code> <code style="color : blue">0000000000000000000000</code>|
|-inf   |0xff800000                        |
|-inf   |   <code style="color : red">1</code> <code style="color : green">11111111</code> <code style="color : blue">0000000000000000000000</code>|
|+NaN   |0x7fc00000|
|+Nan   |   <code style="color : red">0</code> <code style="color : green">11111111</code> <code style="color : blue">1000000000000000000000</code>|


in general: number = (sign ? -1:1) * 2^(exponent) * 1.(mantissa bits)


## Effective FP Programming
Numerical programming is a huge area. Here I'll just try to cover what I think every programmer should know.
### Equality

What do you mean by equality?" equality means "close enough" 

```c++

#define EPSILON 1.0e-7
 
#define flt_equals(a, b) (fabs((a)-(b)) < EPSILON)

```
This method can be very bad, and you should be aware of whether it is appropriate for your application or not. It does not take the exponents of the two numbers into account; it assumes that the exponents are close to zero.

The **precision** of a float is not determined by magnitude but by the **number of correct bits**.
The EPSILON above is a tolerance, a magnitud; it is a statement of how much precision you expect in your results. And precision is measured in significant digits, not in magnitude;
the numbers 1.25e-20 and 2.25e-20. Their difference is 1e-20, much less than EPSILON, but clearly we do not mean them to be equal.
The numbers 1.2500000e-20 and 1.2500001e-20, then we might intend to call them equal.

The take-home message is that when you're defining how close is close enough, you need to talk about how many significant digits you want to match. Answering this question might require some experimentation; try out your algorithm and see how close "equal" results can get.

### Overflow

numerical overflow is one of a programmer's most common concerns.

If you add one to the largest possible unsigned **integer**, the number rolls back to zero. Annoyingly, you **can't tell that this integer overflowed just by looking at it; it looks the same as any zero**. Most CPUs will actually set a flag bit whenever an operation overflows, and checking this bit is one of the few hand-coded assembly language optimizations that are not obsolete.

When **floats** overflow, you are conveniently left with +/-inf. 

This property makes floats useful for **checking overflow in integer math** as well. You can do a calculation in floating point, then simply compare the result to something like INT_MAX before **casting** back to integer.

Be careful with casting, because your float might not have enough precision to preserve an entire integer.  32-bit integer can represent any 9-digit decimal number, but a 32-bit float only offers about 7 digits of precision. So if you have large integers, making this conversion will clobber them. Doubles have enough precision to preserve a whole 32-bit integer but there is an overhead going from float to int or between float and double.

You must try to avoid overflowing results needlessly. Often the final result of a computation is smaller than some of the intermediate values involved; even though your final result is representable, you might overflow during an intermediate step. Avoid this numerical faux pas! 

The classic example (from "[Numerical Recipes in C]"(https://s3.amazonaws.com/nrbook.com/book_C210.html)) is computing the magnitude of a complex number.

### Loss of significance

"Loss of significance" refers to a class of situations where you end up inadvertently losing precision (discarding information) and potentially ending up with laughably bad results.



#### very close quantities substraction

As we have seen, the 1.m representation prevents waste by ensuring that nearly all floats have full precision. 

Even if only the rightmost bit of the mantissa is set (assuming a garden-variety exponent), all the **zeros before it count as significant figures because of that implied 1**. 
However, if we were to subtract two numbers that were very close to each other, the implied ones would cancel, along with whatever mantissa digits matched. If the two numbers differed only in their last bit, our answer would be accurate to only one bit! Ouch!


Take a hard look at all your subtractions any time you start getting suspicious results. 

An example of a technique that might work would be changing polynomials to be functions of 1/x instead of x (this can help when computing the quadratic formula, for one).

#### summing a series of numbers.

If some terms of your series are around an epsilonth of other terms, their contribution is effectively lost if the bigger terms are added first. **Sort** the terms of a series from smallest to largest before summing if this problem is a major concern.


For example, if we start with 1.0 (single precision float) and try to add 1e-8, the result will be 1.0 since 1e-8 is less than epsilon. In this case the small term is swallowed completely. In less extreme cases (with terms closer in magnitude), the smaller term will be swallowed partially—you will lose precision.

If the small terms of your series don't amount to much anyway, then this problem will not bite you. 
A large number of small terms can make a significant contribution to a sum. In these cases, if you're not careful you will keep losing precision until you are left with a mess. 

## A rule of THumb
A float gradually gets "corrupted" as you do more and more operations on it. This makes algorithms with lots of "feedback" (taking previous outputs as inputs) suspect. 

"x += inc" on each iteration, being faster is worst than "x = n*inc" (refreshing it)


when you need a good algorithm for something like solving nonlinear equations, you'll need to look for specialized advice.

## Don't forget about integers
Its accuracy can be a useful tool. You can avoid all the problems of floating point math by storing it as an integer numerator and denominator and regenerating 1.0/denom whenever you need the fraction as a float.

## fixed-point numbers

Digital signal processing (DSP) and game applications are knowledge fields where performance is prefered to precision

53(10) = 0x35 = 00110101 = 0 * 2⁷ + 0 * 2⁶ + 1 * 2⁵ + 1 * 2⁴ + 0 * 2³ + 1 * 2² + 0 * 2¹ + 1 * 2⁰ = 32 + 16 + 4 + 1

53 / 2 = 26.5 

¿How do we represent it if we only have integer?

### Binary point

It is  the key. Acts as decimal point spliting the integer and fractional part of a number.
To the left of the binary point poistive exponents apply.
To the right of the binary point negative exponents apply.

26.5(10) = = 0011010.1 =  0 * 2⁶ +0 * 2⁵ + 1 * 2⁴ + 1 * 2³ + 0 * 2² + 1 * 2¹ + 0 * 2⁰ + 1 * 2-¹= 16 + 8 + 2 + 1/2

### Shifting is the key 
53(10) = 0x35 = 00110101
26(10) = 0x1A = 00011010.1

Shifting the bit pattern of a number to the **right** by 1 bit **divides**    the number by 2. 
Shifting the bit pattern of a number to the **left**  by 1 bit **multiplies** the number by 2.

### Fixed Pôint Representation

To define a fixed point type conceptually, all we need are two parameters:

+ (w) width of the number representation.
+ (b) binary point position within the number counting from the least significative bit 0.

We will use the notation fixed<w,b> 

A bit pattern 22(10) = 00010110 = 2.750<8,3> ==> 0 * 2⁵ + 0 * 2⁴ + 0 * 2³ + 1 * 2¹ + 0 * 2⁰ + 1 * 2⁻1 + 1 * 2⁻2 + 0 * 2⁻3 = 2 + 1/2 + 1/4 = 2 + 0,5 + 0,25 = 2,75
A bit pattern 22(10) = 00010110 = 0.685<8,5> ==> 0 * 2² + 0 * 2¹ + 0 * 2⁰ + 1 * 2⁻1 + 0 * 2⁻2 + 1 * 2⁻3 + 1 * 2⁻4 + 0 * 2⁻5 = 2 + 1/2 + 1/8 + 1/16  = 0,5 + 0,125 + 0.0625 = 0.6875

## Negative Numbers
we use **2's complement** to represent negative numbers. One of the property of 2's complement numbers is that arithmetic operations of either positive of negative numbers are identical. It includes, addition, subtraction, and not surprisingly, shifting. We can divide negative 2's complement numbers by 2 via a simple 1 bit right shift with sign extension as we can do so with positive numbers.

## Pros and Cons

All the arithmetic operations a computer can operate on integer can therefore be applied to fixed point number as well.
fixed point arithmetic is that they are as straight-forward and efficient as integers arithmetic in computers. We can reuse all the hardware 

There is a **loss of range and precision** when compare with floating point number representations

## Using Fixed Point Number in C.

we can simply reuse the integer type int in C to perform fixed point arithmetic. The position of binary point only matters in cases when we print it on screen or perform arithmetic with different "type" (such as when adding int to fixed<32,6>).



## Class limits

The binary point position is 8. There are 24 bits for the integer part. With one bit for the sign the max value is   

|  3L |  3R | 2L  |  2R |  1L | 1R |          |
|-----|-----|-----|-----|-----|----|----------|
|0111 |1111 |1111 |1111 |1111 |1111| = 8388607|
|4321 |0987 |6543 |2109 |8765 |4321|          |
|     |2    |     |  1  |     |    |          |



|a =Binary point ‘s Right Bit position|	1|	2|	3|	4|	5|	6|	7|	8|
|-------------------------------------|--|---|---|---|---|---|---|---|
|b = 2^a|2|4|8|16|32|64|128|256|
|c= 1/b|0,5|0,25|0,125|0,0625|0,03125|0,015625|0,0078125|0,00390625|
|d= sum(c)|0,5|0,75|0,875|0,9375|0,96875|0,984375|0,9921875|0,99609375|

```c++
int const Fixed::_fracbits = 8;
const int Fixed::_MIN_INT_FIXED = -8388607;
const int Fixed::_MAX_INT_FIXED = 8388607;
const float Fixed::_MIN_FLT_FIXED = -8388607.99609375f;
const float Fixed::_MAX_FLT_FIXED = 8388607.99609375f;

```

```bash
$ echo "obase=2 ;8388607.99609375" |bc
+11111111111111111111111.111111110000000000000000000
432109876543210987654321.12345678  32
210987654321098765432109.87654321  32 bits

```

## How my class works

#### Constructors
The int constructor shifts 8 bits to the left its parameter n.

```c++

	this->setRawBits(n << Fixed::_fracbits);
```

The float contructor, **must not** shift 8 bits to the *left*. In fact the compiler claims if you try. 

You can not shift a Floating point. The exponent and mantissa corrupt if you do it.
```bash
Fixed.class.cpp:57:60: error: invalid operands of types ‘const float’ and ‘const int’ to binary ‘operator<<’
   57 |                 this->_N = static_cast<int>( roundf(value  <<  _fracbits));
      |                                                     ~~~~~  ^~  ~~~~~~~~~
      |                                                     |          |
      |                                                     |          const int
      |                                                     const float
```

This is why instead of shifting i **multiply** the float value by two power of 8.
roundf() returns a float with the argument's closest integer, whose result i 
cast to int to fit the setter signature.

```c++
	this->setRawBits(static_cast<int>(roundf(value * (1 <<  _fracbits))i));

```
#### Recovering the values
In the opposite way, to translate the class's internal representation to an integer it is a straight 8 bits *right* shift.

But the translation to float, first cast to float the internal representation that it is **divided** by two power of 8.

#### Arithmetic
I execute arithmetic operations with the float version of the internal representation.

```c++
	return (this->toFloat() + other.toFloat());
```

Each arithmetic operation has its own overflow operation:

| Operation            | Condition                             | Flag          |
|----------------------|---------------------------------------|---------------|
| addition       a + b | if max - a < b                        |  overflow     |
| substraction   a - b | if a < 0 and  min - a < b             |  overflow     |
| multiplicacion a * b | if max / a < b                        |  overflow     |
| division       a / b | if  (a < min * b)  or   (max * b < a) |  overflow     |

#### Epsilon
I use bc to calculate it

```bash
echo "ibase=2; .00000001" |bc
.00390625
```

#### Fixed class inside a loop for

I tested my Fixed Class wiht a loop in this way

```c++
   Fixed initi = Fixed(1.0000000f);
	Fixed limit = Fixed(1.0390625f);
	Fixed refer = Fixed(1.02f );
	for (Fixed i = initi;i <=  limit;i++)
	{
		std::cout << i << " loop "<< idx++ << " i==ee " << refer << " = " << (i == refer) << std::endl;
	}
```

i got ths results

```bash
1.00000loop 0 i==ee 1.01953 = 0
1.00391loop 1 i==ee 1.01953 = 0
1.00781loop 2 i==ee 1.01953 = 0
1.01172loop 3 i==ee 1.01953 = 0
1.01562loop 4 i==ee 1.01953 = 1
1.01953loop 5 i==ee 1.01953 = 1
1.02344loop 6 i==ee 1.01953 = 0
1.02734loop 7 i==ee 1.01953 = 0
1.03125loop 8 i==ee 1.01953 = 0
1.03516loop 9 i==ee 1.01953 = 0
1.03906loop 10 i==ee 1.01953 = 0
1.04297loop 11 i==ee 1.01953 = 0

```

### Bonus ex03 BSP
The subject request to create const attributes

```c++
	Fixed const _x;
    Fixed const _y;

```

I got a several compilation errors inside constructors and the assigment operator overload.

I solve the problem in the constructors with the initialitation list.
 
Inside the assigment operator instead copy attribute by attribute i instantiate a new object Point and assigned it to this

```c++
Point &  Point::operator=(const Point & other)
{

	if (this != &other)
	{
		*this = Point(other);
	}
	return *this; 
}
```

# what I read
+ [Understanding and Using Floating Point Numbers](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html)
+ [Floating point number representation](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html)
+ [Printing floating point numbers](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html)
+ [Introduction to Fixed Point Number Representation](https://inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html)
