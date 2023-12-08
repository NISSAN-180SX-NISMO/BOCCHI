import os
import re

def scan_components(directory):
    print('run scan_components...')
    component_names = set()
    matching_files = set()

    # Директории, которые нужно исключить из поиска
    exclude_dirs = {'Bocchi', 'cmake-build-debug', 'venv'}

    for root, dirs, files in os.walk(directory):
        # Исключаем указанные директории из поиска
        dirs[:] = [d for d in dirs if d not in exclude_dirs]

        for file in files:
            if file.endswith(('.h', '.hpp')):
                file_path = os.path.join(root, file)
                with open(file_path, 'r') as f:
                    content = f.read()
                    matches = re.findall(r'COMPONENT\((\w+)\)', content)
                    if matches:
                        component_names.update(matches)
                        matching_files.add(os.path.relpath(file_path, directory))

    with open('../BocchiApplication/IncludeComponents.h', 'w') as includes_file:
        for component_name, relative_path in zip(component_names, matching_files):
            includes_file.write(f'#include "../../{relative_path}"\n')

if __name__ == "__main__":
    scan_components('../../')
