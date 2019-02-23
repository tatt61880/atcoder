#include <stdio.h>

int main(void)
{
	int A, B, C;
	scanf("%d%d %d", &A, &B, &C);

	if(B == 0){
		if(A == C){
			puts("?");
		}else{
			puts("!");
		}
	}else{
		if(A + B == C){
			puts("+");
		}else if(A - B == C){
			puts("-");
		}else{
			puts("!");
		}
	}
	return 0;
}
</pr
e>

		<h4>Submission Info</h4>
		<div class="panel panel-default"><table class="table table-bordered table-striped">
			<tr>
				<th class="col-sm-4">Submission Time</th>
				<td class="text-center"><time class='fixtime fixtime-second'>2016-02-11 19:20:06+0900</time></td>
			</tr>
			<tr>
				<th>Task</th>
				<td class="text-center"><a href='/contests/abc016/tasks/abc016_2'>B - A±B Problem</a></td>
			</tr>
			<tr>
				<th>User</th>
				<td class="text-center"><a href='/users/tatt61880'>tatt61880</a> <a href='/contests/abc016/submissions?f.User=tatt61880'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view tatt61880's submissions'></span></a></td>
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
				<td class="text-center">296 Byte</td>
			</tr>
			<tr>
				<th>Status</th>
				<td class="text-cen
ter"><span class='label label-success' aria-hidden='true' data-toggle='tooltip' data-placement='top' title="Accepted">AC</span></td>
			</tr>
			
				<tr>
					<th>Exec Time</th>
					<td class="text-center">27 ms</td>
				</tr>
				<tr>
					<th>Memory</th>
					<td class="text-center">840 KB</td>
				</tr>
			
		</table></div>

		
		<h4>Compile Error</h4>
		<pre>./Main.cpp: In function ‘int main()’:
./Main.cpp:6:30: warning: ignoring return value of ‘int scanf(const char*, ...)’, declared with attribute warn_unused_result [-Wunused-result]
