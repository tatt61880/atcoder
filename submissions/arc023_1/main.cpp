#include <stdio.h>

int calc(int y, int m, int d)
{
	if(m <= 2) {y--; m += 12;}
	m++;
	return	365 * y + y / 4 - y / 100 + y / 400 + 306 * m / 10 + d - 429;
}

int main(void)
{
	int y, m, d;
	scanf("%d%d%d", &y, &m, &d);
	printf("%d\n", calc(2014, 5, 17) - calc(y, m, d));
	return 0;
}
</pr
e>

		<h4>Submission Info</h4>
		<div class="panel panel-default"><table class="table table-bordered table-striped">
			<tr>
				<th class="col-sm-4">Submission Time</th>
				<td class="text-center"><time class='fixtime fixtime-second'>2016-02-13 19:39:01+0900</time></td>
			</tr>
			<tr>
				<th>Task</th>
				<td class="text-center"><a href='/contests/arc023/tasks/arc023_1'>A - 経過日数</a></td>
			</tr>
			<tr>
				<th>User</th>
				<td class="text-center"><a href='/users/tatt61880'>tatt61880</a> <a href='/contests/arc023/submissions?f.User=tatt61880'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view tatt61880's submissions'></span></a></td>
			</tr>
			<tr>
				<th>Language</th>
				<td class="text-center">C++ (G++ 4.6.4)</td>
			</tr>
			<tr>
				<th>Score</th>
				<td class="text-center">100</td>
			</tr>
			<tr>
				<th>Code Size</th>
				<td class="text-center">301 Byte</td>
			</tr>
			<tr>
				<th>Status</th>
				<td class="text-center"><s
pan class='label label-success' aria-hidden='true' data-toggle='tooltip' data-placement='top' title="Accepted">AC</span></td>
			</tr>
			
				<tr>
					<th>Exec Time</th>
					<td class="text-center">24 ms</td>
				</tr>
				<tr>
					<th>Memory</th>
					<td class="text-center">804 KB</td>
				</tr>
			
		</table></div>

		
		<h4>Compile Error</h4>
		<pre>./Main.cpp: In function ‘int main()’:
./Main.cpp:13:29: warning: ignoring return value of ‘int scanf(const char*, ...)’, declared with attribute warn_unused_result [-Wunused-result]
