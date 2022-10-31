# [Silver I] Measuring Traffic - 17041 

[문제 링크](https://www.acmicpc.net/problem/17041) 

### 성능 요약

메모리: 1992 KB, 시간: 0 ms

### 분류

구현(implementation)

### 문제 설명

<p>The highway adjacent to Farmer John's farm has recently seen a dramatic increase in traffic, or at least so it seems to Farmer John. To be sure, he wants to measure the traffic flow on the highway with a set of sensors, each capable of measuring the rate of flow of traffic on a segment of road.</p>

<p>Unfortunately, while walking through the barn one day, Farmer John trips and drops his box of sensors into a large vat of milk, after which they no longer work as well. Instead of producing a single exact reading of traffic flow rate, each sensor now outputs a range of possible values. For example, a sensor might output the range $[7, 13]$, indicating that the rate of traffic flow on a segment of road is no less than 7, and no greater than 13.</p>

<p>The highway runs for $N$ miles next to the farm, and traffic on the highway only flows in one direction, from mile 1 towards mile $N$. Farmer John wants to install $N$ sensors -- one for each 1-mile segment of the highway. In some of these segments, there are on-ramps that allow traffic to enter the highway; in each of these cases, Farmer John will install his sensor on the on-ramp to measure (approximately) the amount of incoming traffic. In some segments there are off-ramps that allows traffic to exit the highway; in each of these cases, Farmer John will install his sensor on the off-ramp. Each segment contains at most one ramp. If there is no on-ramp or off-ramp in a segment of highway, Farmer John installs a sensor on the main highway itself.</p>

<p>Given the readings from Farmer John's $N$ sensors, please determine the most specific possible ranges that describe the rate of traffic flow initially on the highway prior to mile 1 and for traffic continuing on the highway past mile $N$. These ranges should be consistent with all $N$ sensor readings.</p>

### 입력 

 <p>The first line of input contains $N$ ($1 \leq N \leq 100$). Each of the remaining $N$ lines describes a 1-mile segment of the road, in order from mile $1$ to mile $N$. Each line contains a string that is either "on" (if there is an on-ramp on this segment), "off" (if there is an off-ramp), or "none" (if there is no ramp), followed by two integers in the range $0 \ldots 1000$, indicating the lower and upper endpoints of the sensor range from this segment. If the segment contains a ramp, the sensor reading is from the ramp. Otherwise, it is from the main highway. At least one of the highway segments will be designated as "none".</p>

### 출력 

 <p>The first line of output should contain two integers giving the most specific range possible for the rate of traffic flow prior to mile 1. The second line of output should contain two integers giving the most specific range possible for the rate of traffic flow after mile $N$. A valid solution is always guaranteed to exist.</p>

