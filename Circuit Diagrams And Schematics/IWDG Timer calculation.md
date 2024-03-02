- PSC = Prescalar Value
- RL = Reload Value
- Fclk = Timer clock frequency of Highspeed internal oscillator
- t = Time in Seconds

This is the forumla for working out how long the IWDG can run before it needs refreshed.

$$ t = \frac{1}{Fclk} * PSC * RL $$

We can pick a time we want, a prescalar value and from that we can workout what value we need for RL.

Let's say we pick a prescalar value of 128 and we want a time of 3 seconds before the watchdog needs refreshed

$$ RL = \frac{t * Fclk}{PSC} $$

Now we can workout the value of RL for a 3 second delay

$$ RL = \frac{3 * 40000}{128} = 937.5 $$

Rounded up we use $ 938 $

