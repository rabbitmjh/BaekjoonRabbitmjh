# [Silver I] Taming the Herd - 15753 

[문제 링크](https://www.acmicpc.net/problem/15753) 

### 성능 요약

메모리: 2380 KB, 시간: 0 ms

### 분류

구현(implementation)

### 문제 설명

<p>Early in the morning, Farmer John woke up to the sound of splintering wood. It was the cows, and they were breaking out of the barn again!</p>

<p>Farmer John was sick and tired of the cows' morning breakouts, and he decided enough was enough: it was time to get tough. He nailed to the barn wall a counter tracking the number of days since the last breakout. So if a breakout occurred in the morning, the counter would be $0$ that day; if the most recent breakout was $3$ days ago, the counter would read $3$. Farmer John meticulously logged the counter every day.</p>

<p>The end of the year has come, and Farmer John is ready to do some accounting. The cows will pay, he says! But lo and behold, some entries of his log are missing!</p>

<p>Farmer John is confident that the he started his log on the day of a breakout. Please help him determine, out of all sequences of events consistent with the log entries that remain, the minimum and maximum number of breakouts that may have take place over the course of the logged time.</p>

### 입력 

 <p>The first line contains a single integer $N$ ($1 \leq N \leq 100$), denoting the number of days since Farmer John started logging the cow breakout counter.</p>

<p>The second line contains $N$ space-separated integers. The $i$th integer is either $-1$, indicating that the log entry for day $i$ is missing, or a non-negative integer $a_i$ (at most $100$), indicating that on day $i$ the counter was at $a_i$.</p>

### 출력 

 <p>If there is no sequence of events consistent with Farmer John's partial log and his knowledge that the cows definitely broke out of the barn on the morning of day $1$, output a single integer $-1$. Otherwise, output two space-separated integers $m$ followed by $M$, where $m$ is the minimum number of breakouts of any consistent sequence of events, and $M$ is the maximum.</p>

