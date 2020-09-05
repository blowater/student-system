if (status == 2)//教师

		{

			if (man_login() == 1)

			{

			
				int menu_return = man_menu();

				while (1)

				{

					switch (menu_return)//功能 

					{

					case 1:

						student_add(stu_head); break;

					case 2:

						student_delete(stu_head); break;

					case 3:

						student_modify(stu_head); break;

					case 4:

						man_search_stu(stu_head); break;

					case 5:

						course_add(cour_head); break;

					case 6:

						course_delete(cour_head); break;

					case 7:

						course_modify(cour_head); break;

					case 8:

						search_course(cour_head); break;

					case 9:

						print_all(); break;

					case 10:

						man_modifyKey(); break;

					case 11:

						man_backups_recover(); break;

					case 0:

						break;

					default:

						printf("\t\t\t#####输入错误，请重新输入######!\n");

					}

 

					if (menu_return == 0)

						break;

					menu_return = man_menu();

				}

			}

			else

				printf("\t\t######密码错误，请重新登陆!######\n");

		}

 
