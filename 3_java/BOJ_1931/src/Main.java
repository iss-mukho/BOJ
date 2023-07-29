import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
	static ArrayList<Meeting> Meetings = new ArrayList<>();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		int N = Integer.parseInt(br.readLine());
		for(int i = 0; i < N; ++i) {
			st = new StringTokenizer(br.readLine());
			Meetings.add(new Meeting(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
		}

		Collections.sort(Meetings);

		int answer = 1;
		int roomEnd = Meetings.get(0).endTime;
		for(int i = 1; i < N; ++i) {
			Meeting currentMeeting = Meetings.get(i);
			if(roomEnd > currentMeeting.startTime) continue;
			++answer;
			roomEnd = currentMeeting.endTime;
		}

		bw.write(answer + "\n");
		bw.flush();
		br.close();
		bw.close();
	}
}

class Meeting implements Comparable<Meeting> {
	int startTime;
	int endTime;

	public Meeting(int startTime, int endTime) {
		this.startTime = startTime;
		this.endTime = endTime;
	}

	@Override
	public int compareTo(Meeting other) {
		if(this.endTime == other.endTime) return this.startTime - other.startTime;
		return this.endTime - other.endTime;
	}
}