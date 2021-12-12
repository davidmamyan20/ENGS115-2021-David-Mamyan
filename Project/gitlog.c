#include<stdio.h>
#include<json-c/json.h>

void access_json(int argc, char **argv) {
	FILE *fp;
	char buffer[1024];
	struct json_object *parsed_json;
	struct json_object *name;
	struct json_object *data;
	struct json_object *body;
	size_t n_name;
	size_t n_data;
	size_t n_body;
	size_t i;


	fp = fopen("commits.json","r");
	fread(buffer, 1024, 1, fp);
	fclose(fp);

	parsed_json = json_tokener_parse(buffer);

	json_object_object_get_ex(parsed_json, "name", &name);
	json_object_object_get_ex(parsed_json, "data", &data);
	json_object_object_get_ex(parsed_json, "body", &body);

        	
	
	printf("Name: %s\n", json_object_get_string(name));
	printf("Data: %s\n", json_object_get_string(data));
	printf("Body: %s\n", json_object_get_string(body));
		
}

void sort_by_name()
{
	//Will search the commits done by a certain person
}
void sort_by_date()
{
	//will sort all the commits according to date
}
void representation()
{
	//will show all the commits in a the new way
}

void convert_to_html()
{
	//Convert the json file to html
}
void filter_out()
{
	//use the filter in our code
}
void main()
{
	int argc;
	char **argv;
	access_json(argc,argv);
  //the main part of the code
}


