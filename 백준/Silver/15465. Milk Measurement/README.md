# [Silver II] Milk Measurement - 15465 

[문제 링크](https://www.acmicpc.net/problem/15465) 

### 성능 요약

메모리: 1988 KB, 시간: 0 ms

### 분류

구현(implementation), 시뮬레이션(simulation), 정렬(sorting)

### 문제 설명

<p>Farmer John purchases three cows: Bessie, Elsie, and Mildred, each of whom initially produces 7 gallons of milk per day. Since the milk output of a cow is known to potentially change over time, Farmer John takes periodic measurements over the next 100 days and scribbles them down in a log book. Entries in his log look like this:</p>

<pre>35 Bessie -2
14 Mildred +3
</pre>

<p>The first entry indicates that on day 35, Bessie's milk output was 2 gallons lower than it was when last measured. The next entry indicates that on day 14, Mildred's milk output increased by 3 gallons from when it was last measured. Farmer John has only enough time to make at most one measurement on any given day. Unfortunately, he is a bit disorganized, and doesn't necessarily write down his measurements in chronological order.</p>

<p>To keep his cows motivated, Farmer John proudly displays on the wall of his barn the picture of whichever cow currently has the highest milk output (if several cows tie for the highest milk output, he displays all of their pictures). Please determine the number of days on which Farmer John would have needed to change this display.</p>

### 입력 

 <p>The first line of input contains $N$, the number of measurements Farmer John makes. Each of the next $N$ lines contains one measurement, in the format above, specifying a day (an integer in the range 1..100), the name of a cow, and the change in her milk output since it was last measured (a nonzero integer). Each cow's milk output will always be in the range 0..1000.</p>

### 출력 

 <p>Please output the number of days (an integer in the range 0..100) on which Farmer John needs to adjust his motivational display.</p>

