<h1> Morse Code Reader</h1>
<p> Press a button connected to an Arduino with Morse Code and output letters </p>

<!-- TABLE OF CONTENTS -->
## Table of Contents

* [About the Project](#about-the-project)
  * [Built With](#built-with)
* [How it Functions](#getting-started)
* [Usage](#usage)




<!-- ABOUT THE PROJECT -->
## About The Project




### Built With
* C
* atmelStudio
* Arduino


<!-- GETTING STARTED -->
## How it Functions

The idea is to essentially run through the logic like this:
 
1. Use an overflow interrupt and an incremental counter to measure about 4ms of time.

2. Only run that overflow counter if the button is pressed.

3. If the button is unpressed (meaning we are no longer holding it down trying to create a dash or dot) AND the overflow counter has some value between our set parameters (we use the 4 and some ms for each count of the overflow, so a dot is between 7 and 49 counts or 29 to 200ish ms, a dash is between 49 and 98 counts or 200-400ish ms, etc), then we will count a dot or dash depending on the value of count. We also include a short blink of an LED when a dot or dash is reached so we know which one we pressed. In my case, the dot was blue and the dash was yellow.

4. Once we print our value it will always reset our overflow counter.

5. We run a separate counter, space_count, that counts how long the button is unpressed, and if that exceeds 98 counts or 400ish ms, we count a space and reset space_count (dots and dashes reset space_count as well so we don't keep looking for a space when we mean to count a dot or dash).

6. We store whether we counted a dot or dash by appending to an array that is allowed up to 5 integers. 0 for dot and 1 for dash. If we enter the conditions for dot, we simply change the first element of the array to 0, then we use another counter to cycle which element of the array we are changing. Note, the array starts out as {2,2,2,2,2} so that if a morse code element is only 3 bits, say 001, we use the 2's as placeholders since 1's or 0's will give us unintended characters.

7. Once we are ready to check the value of the array, we simply wait until a space is reached. The space will call a separate function which checks the value of each element of the array. It uses a set of if statments to compare the bits we stored in the array to all the bits we would get from converting dots to 0's and dashes to 1's in morse code. When we find a match for our array, we print the letter, and add a line break. We also reset our array to {2,2,2,2,2} so that we don't print any new characters every time we count a space.

8. We can repeat this process to spell out any alphanumeric combination using the standard roman alphabet and arabic numerals.



<!-- USAGE EXAMPLES -->
## Usage
A Youtube explanation and demonstration of the script: https://youtu.be/2jPR1-nJ1Hs




<!-- CONTACT -->
## Contact

Made by Mostafa Afr

