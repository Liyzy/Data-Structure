#include "TextEditor.h"

int main()
{
	TextEditor editor;

	editor.getfile();
	while (1)
	{
		editor.Help();
	}

	system("pause");
	return 0;
}