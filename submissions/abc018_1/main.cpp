#include <stdio.h>

int main(void)
{
	int a, b, c;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	printf("%d\n", 1 + (a < b) + (a < c));
	printf("%d\n", 1 + (b < a) + (b < c));
	printf("%d\n", 1 + (c < a) + (c < b));
	return 0;
}
</pr
e>

		<h4>Submission Info</h4>
		<div class="panel panel-default"><table class="table table-bordered table-striped">
			<tr>
				<th class="col-sm-4">Submission Time</th>
				<td class="text-center"><time class='fixtime fixtime-second'>2016-02-08 23:21:40+0900</time></td>
			</tr>
			<tr>
				<th>Task</th>
				<td class="text-center"><a href='/contests/abc018/tasks/abc018_1'>A - 豆まき</a></td>
			</tr>
			<tr>
				<th>User</th>
				<td class="text-center"><a href='/users/tatt61880'>tatt61880</a> <a href='/contests/abc018/submissions?f.User=tatt61880'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view tatt61880's submissions'></span></a></td>
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
				<td class="text-center">251 Byte</td>
			</tr>
			<tr>
				<th>Status</th>
				<td class="text-center"><sp
an class='label label-success' aria-hidden='true' data-toggle='tooltip' data-placement='top' title="Accepted">AC</span></td>
			</tr>
			
				<tr>
					<th>Exec Time</th>
					<td class="text-center">53 ms</td>
				</tr>
				<tr>
					<th>Memory</th>
					<td class="text-center">1920 KB</td>
				</tr>
			
		</table></div>

		
		<h4>Compile Error</h4>
		<pre>./Main.cpp: In function ‘int main()’:
./Main.cpp:6:17: warning: ignoring return value of ‘int scanf(const char*, ...)’, declared with attribute warn_unused_result [-Wunused-result]
./Main.cpp:7:17: warning: ignoring return value of ‘int scanf(const char*, ...)’, declared with attribute warn_unused_result [-Wunused-result]
./Main.cpp:8:17: warning: ignoring return value of ‘int scanf(const char*, ...)’, declared with attribute warn_unused_result [-Wunused-result]
