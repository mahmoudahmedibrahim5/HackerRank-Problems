#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING_LENGTH 6

struct package
{
	char* id;
	int weight;
};

typedef struct package package;

struct post_office
{
	int min_weight;
	int max_weight;
	package* packages;
	int packages_count;
};

typedef struct post_office post_office;

struct town
{
	char* name;
	post_office* offices;
	int offices_count;
};

typedef struct town town;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////// Start of the Answer ////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void print_all_packages(town t) {
    printf("%s:\n",t.name);
    for(int i=0; i<t.offices_count; i++)
    {
        printf("\t%d:\n", i);
        for(int j=0; j<t.offices[i].packages_count; j++)
        {
            printf("\t\t%s\n", t.offices[i].packages[j].id);
        }
    }
}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {
		
		/* number of packages in the source after sending packages which is also number of unsent packages */
		int newSource_packages_count = 0;
		/* number of packages already found in the target before transition */
		int oldTarget_packages_count = target->offices[target_office_index].packages_count; 
		/* number of packages in the target after sending packages 
		 * which is also number of sent packages + number of packages already found in the target before transition 
		 */
		int newTarget_packages_count = oldTarget_packages_count;
		 
		/* Packages which will be transmitted and their count */
		int Transition_length = source->offices[source_office_index].packages_count;
		package* Transition_packages = malloc(sizeof(package) * Transition_length);
		for (int i = 0; i < Transition_length; i++){
			Transition_packages[i].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
		}


		/* Assign Packages which will be transmitted to Transition Packages array
		 * Calculate newSource_packages_count and newTarget_packages_count 
		 */
		for (int i = 0; i < Transition_length; i++)
		{
			strcpy(Transition_packages[i].id, source->offices[source_office_index].packages[i].id);
			Transition_packages[i].weight = source->offices[source_office_index].packages[i].weight;
			// check if the weight is greater than max weight or less than min weight
			if ((source->offices[source_office_index].packages[i].weight > target->offices[target_office_index].max_weight) || (source->offices[source_office_index].packages[i].weight < target->offices[target_office_index].min_weight))
				newSource_packages_count++;
			else
				newTarget_packages_count++;
		}

		/* Update source with new packages count and reallocate size of packages array */
		source->offices[source_office_index].packages_count = newSource_packages_count;
		source->offices[source_office_index].packages = realloc(source->offices[source_office_index].packages, sizeof(package) * newSource_packages_count);
		for (int i = 0; i < newSource_packages_count; i++){
			source->offices[source_office_index].packages[i].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
		}

		/* Update target with new packages count and reallocate size of packages array */
		target->offices[target_office_index].packages_count = newTarget_packages_count;
		target->offices[target_office_index].packages = realloc(target->offices[target_office_index].packages, sizeof(package) * newTarget_packages_count);
		for (int i = oldTarget_packages_count; i < newTarget_packages_count; i++){
			target->offices[target_office_index].packages[i].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
		}

		/* Assign transmited packages to target and untransmitted to source */
		int source_index = 0;
		int target_index = oldTarget_packages_count;
		for (int i = 0; i < Transition_length; i++)
		{
			if (Transition_packages[i].weight > target->offices[target_office_index].max_weight || Transition_packages[i].weight < target->offices[target_office_index].min_weight)
			{
				strcpy(source->offices[source_office_index].packages[source_index].id, Transition_packages[i].id);
				source->offices[source_office_index].packages[source_index].weight = Transition_packages[i].weight;
				source_index++;
			}
			else
			{
				strcpy(target->offices[target_office_index].packages[target_index].id, Transition_packages[i].id);
				target->offices[target_office_index].packages[target_index].weight = Transition_packages[i].weight;
				target_index++;
			}
		}

		/* free allocated space */
		for (int i = 0; i < Transition_length; i++)
		{
			free(Transition_packages[i].id);
		}
		free(Transition_packages);
}

town town_with_most_packages(town* towns, int towns_count) {
	int *towns_packages = calloc(towns_count, sizeof(int));
	int max_index = 0;
	for (int i = 0; i < towns_count; i++)
	{
		for (int j = 0; j < towns[i].offices_count; j++){
			// Sum of packages of all ofices in ith town
			towns_packages[i] += towns[i].offices[j].packages_count;
		}
		// Check if the sum of the new town is greater than last max, then update the max to be that town
		if (towns_packages[i] > towns_packages[max_index])
			max_index = i;
	}
	free(towns_packages);
	return towns[max_index];
}

town* find_town(town* towns, int towns_count, char* name) {
	int i;
	for (i = 0; i < towns_count; i++)
	{
		if(!(strcmp(towns[i].name, name)))
			break;
	}
	return &towns[i];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////// End of the Answer /////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	int towns_count;
	scanf("%d", &towns_count);
	town* towns = malloc(sizeof(town)*towns_count);
	for (int i = 0; i < towns_count; i++) {
		towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
		scanf("%s", towns[i].name);
		scanf("%d", &towns[i].offices_count);
		towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
		for (int j = 0; j < towns[i].offices_count; j++) {
			scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
			towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
			for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
				towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
				scanf("%s", towns[i].offices[j].packages[k].id);
				scanf("%d", &towns[i].offices[j].packages[k].weight);
			}
		}
	}
	int queries;
	scanf("%d", &queries);
	char town_name[MAX_STRING_LENGTH];
	while (queries--) {
		int type;
		scanf("%d", &type);
		switch (type) {
		case 1:
			scanf("%s", town_name);
			town* t = find_town(towns, towns_count, town_name);
			print_all_packages(*t);
			break;
		case 2:
			scanf("%s", town_name);
			town* source = find_town(towns, towns_count, town_name);
			int source_index;
			scanf("%d", &source_index);
			scanf("%s", town_name);
			town* target = find_town(towns, towns_count, town_name);
			int target_index;
			scanf("%d", &target_index);
			send_all_acceptable_packages(source, source_index, target, target_index);
			break;
		case 3:
			printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
			break;
		}
	}
	return 0;
}
