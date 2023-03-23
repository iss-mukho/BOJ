// 백준 1931: 회의실 배정(실버 I), https://www.acmicpc.net/problem/1931
import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {

    public static class MeetingType{
        int startTime;
        int endTime;

        public MeetingType(int startTime, int endTime) {
            this.startTime = startTime;
            this.endTime = endTime;
        }
    }

    static ArrayList<MeetingType> meeting = new ArrayList<>();
    static int meetingCount;
    static int possibleMeetingCount = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        // 입력
        st = new StringTokenizer(br.readLine());
        meetingCount = Integer.parseInt(st.nextToken());

        for(int i=0; i<meetingCount; ++i){
            st = new StringTokenizer(br.readLine());
            int startTime = Integer.parseInt(st.nextToken()), endTime = Integer.parseInt(st.nextToken());
            meeting.add(new MeetingType(startTime, endTime));
        }

        // 처리
        Collections.sort(meeting, (meet1, meet2) -> (meet1.endTime != meet2.endTime) ? meet1.endTime - meet2.endTime : meet1.startTime - meet2.startTime);
        int currentTime = 0;
        for(var currentMeeting: meeting){
            int startTime = currentMeeting.startTime, endTime = currentMeeting.endTime;

            if(startTime < currentTime) continue;

            currentTime = endTime;
            ++possibleMeetingCount;
        }

        // 출력
        bw.write(possibleMeetingCount + "\n");

        br.close();
        bw.close();
    }
}
