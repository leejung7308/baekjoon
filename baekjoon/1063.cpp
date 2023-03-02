//#include<stdio.h>
//#include<string.h>
//int main() {
//	char king[3], rock[3];
//	int n;
//	scanf("%s %s %d", king, rock, &n);
//	for (int i = 0; i < n; i++)
//	{
//		char tmp[3];
//		scanf("%s", tmp);
//		if (strcmp(tmp, "R") == 0) {
//			if (king[0] + 1 == 'I') continue;
//			else king[0] += 1;
//			if (strcmp(king, rock) == 0) {
//				if (rock[0] + 1 == 'I') king[0] -= 1;
//				else rock[0] += 1;
//			}
//		}
//		else if (strcmp(tmp, "L") == 0) {
//			if (king[0] - 1 == 'A'-1) continue;
//			else king[0] -= 1;
//			if (strcmp(king, rock) == 0) {
//				if (rock[0] - 1 == 'A'-1) king[0] += 1;
//				else rock[0] -= 1;
//			}
//		}
//		else if (strcmp(tmp, "B") == 0) {
//			if (king[1] - 1 == '1' - 1) continue;
//			else king[1] -= 1;
//			if (strcmp(king, rock) == 0) {
//				if (rock[1] - 1 == '1' - 1) king[1] += 1;
//				else rock[1] -= 1;
//			}
//		}
//		else if (strcmp(tmp, "T") == 0) {
//			if (king[1] + 1 == '9') continue;
//			else king[1] += 1;
//			if (strcmp(king, rock) == 0) {
//				if (rock[1] + 1 == '9') king[1] -= 1;
//				else rock[1] += 1;
//			}
//		}
//		else if (strcmp(tmp, "RT") == 0) {
//			if (king[1] + 1 == '9' || king[0] + 1 == 'I') continue;
//			else {
//				king[1] += 1;
//				king[0] += 1;
//			}
//			if (strcmp(king, rock) == 0) {
//				if (rock[1] + 1 == '9' || rock[0] + 1 == 'I') {
//					king[1] -= 1;
//					king[0] -= 1;
//				}
//				else {
//					rock[1] += 1;
//					rock[0] += 1;
//				}
//			}
//		}
//		else if (strcmp(tmp, "LT") == 0) {
//			if (king[1] + 1 == '9' || king[0] - 1 == 'A' - 1) continue;
//			else {
//				king[1] += 1;
//				king[0] -= 1;
//			}
//			if (strcmp(king, rock) == 0) {
//				if (rock[1] + 1 == '9' || rock[0] - 1 == 'A' - 1) {
//					king[1] -= 1;
//					king[0] += 1;
//				}
//				else {
//					rock[1] += 1;
//					rock[0] -= 1;
//				}
//			}
//		}
//		else if (strcmp(tmp, "RB") == 0) {
//			if (king[1] - 1 == '1'-1 || king[0] + 1 == 'I') continue;
//			else {
//				king[1] -= 1;
//				king[0] += 1;
//			}
//			if (strcmp(king, rock) == 0) {
//				if (rock[1] - 1 == '1'-1 || rock[0] + 1 == 'I') {
//					king[1] += 1;
//					king[0] -= 1;
//				}
//				else {
//					rock[1] -= 1;
//					rock[0] += 1;
//				}
//			}
//		}
//		else if (strcmp(tmp, "LB") == 0) {
//			if (king[1] - 1 == '1'-1 || king[0] - 1 == 'A'-1) continue;
//			else {
//				king[1] -= 1;
//				king[0] -= 1;
//			}
//			if (strcmp(king, rock) == 0) {
//				if (rock[1] - 1 == '1'-1 || rock[0] - 1 == 'A'-1) {
//					king[1] += 1;
//					king[0] += 1;
//				}
//				else {
//					rock[1] -= 1;
//					rock[0] -= 1;
//				}
//			}
//		}
//	}
//	printf("%s\n%s", king, rock);
//}