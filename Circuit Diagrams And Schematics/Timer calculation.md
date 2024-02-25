- PSC = Prescalar Value
- ARR = Auto-Reload Register Value
- Fclk = Timer clock frequency
- t = Time in seconds

$$ t = \frac{(ARR + 1)(PSC + 1)}{Fclk}$$

If we want a 1 second timer, we can pick an arbitrary prescalra value of 1000 for example.

We can calculate the ARR value to allow us to get that 1 second delay using the above formula transposed:

$$ ARR = \frac{T * Fclk}{PSC + 1} - 1$$

From the datasheet and CUBEMx we can see that the clock frequency is set to 32MHz in our example, so...

$$ ARR = \frac{1 * 64MHz}{2000 + 1} - 1$$

$$ ARR = 31984$$

Now we have the ARR and PSC value we can use in our timer setup