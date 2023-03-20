#CPP Module 09

####I thought the series of cpp modules was over, but I was stuck.
<p> You must use at least one container for each exercise with the exception of exercise 02 which requires the use of two containers.</p>

####Except for ex02, you must use at least one container.

#ex00

######Bitcoin Exchange
<p>You have to create a program which outputs the value of a certain amount of bitcoin on a certain date.</p>

- Create a program that outputs the value of a specific bitcoin on a specific date.

- This program must use a database in csv format which will represent bitcoin price over time. This database is provided with this subject.

- This program must use a csv-formatted database representing bitcoin prices over time. This database comes with the subject.

💡CSV?

CSV (comma-separated values) is a text file with fields separated by commas (,). The extension is .csv, and the MIME format is text/csv.

example:

*/ date,exchange_rate
2009-01-02,0
(...)
2014-02-11,675.1 */

- The program will take as input a second database, storing the different prices/dates to evaluate.
- The program receives the second database as an argument. It stores the price and date to be evaluated.

Your program must respect these rules:
- Programs must follow the rules above.

- The program name is btc.

- Your program must take a file as argument.

- Each line in this file must use the following format: "date | value".

- A valid date will always be in the following format: Year-Month-Day.

- A valid value must be either a float or a positive integer between 0 and 1000.

Here is an example of an input.txtfile:

$> head input.txt

<p>date | value</p>

date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648

<p> Your program should display on the standard output the result of the value multiplied by the exchange rate according to the date indicated in your database.</p>

If the date used in the input does not exist in your DB then you must use the closest date contained in your DB.

Be careful to use the lower date and not the upper one.

The following is an example of the program's use.

$> ./btc
Error: could not open file.

<p>$&gt; ./btc input.txt</p>
<p>2011-01-03 =&gt; 3 = 0.9</p>
<p>2011-01-03 =&gt; 2 = 0.6</p>
<p>2011-01-03 =&gt; 1 = 0.3</p>
<p>2011-01-03 =&gt; 1.2 = 0.36</p>
<p>2011-01-09 =&gt; 1 = 0.32</p>
<p>Error: not a positive number.</p>
<p>Error: bad input =&gt; 2001-42-42</p>
<p>2012-01-11 =&gt; 1 = 7.1</p>
<p>Error: too large a number.</p>
<p>$&gt;</p>

💡 Warning

The container(s) you use to validate this exercise will no longer be usable for the rest of this module.


#ex01

####Before we get into it, RPN (Reverse Polish Notation)?

The calculation method (which we commonly use) in the image above is called the standard arithmetic method, infix notation.

That is, if in the image above 2 + 2 x 2is written as RPN, 2 2 * 2 +it is .

RPNs help reduce errors in complex calculations by eliminating the need for parentheses and not having to worry about precedence, which is said to be particularly useful for computer programming and calculators.

Anyway, this is called reverse Polish notation (RPN) or postfix notation .

###subject

You must create a program with these constraints:
• The program name is RPN.
• Your program must take an inverted Polish mathematical expression as an argument.
• The numbers used in this operation and passed as arguments will always be less than 10. The calculation itself but also the result do not take into account this rule.
• Your program must process this expression and output the correct result on the standard output.
• If an error occurs during the execution of the program an error message should be displayed on the standard output.
• Your program must be able to handle operations with these tokens: "+ - / *". You must use at least one container in your code to validate this exercise.

