import subprocess
import os
import shutil

def clone_repository(repo_url, target_dir):
    try:
        print(f'Cloning {repo_url} into {target_dir}...')
        subprocess.run(['git', 'clone', repo_url, target_dir], check=True)
        print('Repository cloned successfully.')

    except subprocess.CalledProcessError as e:
        print(f'Error cloning repository: {e}')
        exit(1)

def replace_files(modified_files_path, git_repo_path):
    for root, dirs, files in os.walk(modified_files_path):

        rel_path = os.path.relpath(root, modified_files_path)
        target_path = os.path.join(git_repo_path, rel_path)
        
        # Check if the target directory exists
        os.makedirs(target_path, exist_ok=True)
        
        for file in files:
            src_file = os.path.join(root, file)
            dst_file = os.path.join(target_path, file)
            shutil.copy2(src_file, dst_file)
            print(f'Copied {src_file} to {dst_file}')

if __name__ == '__main__':

    # 
    # Proteus Firmware
    # 
    repo_name = 'fehproteusfirmware'
    repo_url = f'https://code.osu.edu/fehelectronics/proteus_software/{repo_name}.git'

    target_dir = f'FEH/{repo_name}'
    git_repo_path = os.path.join(os.getcwd(), target_dir)

    clone_repository(repo_url, target_dir)

    modified_files_path = f'install_scripts/mod_files/{repo_name}'
    replace_files(modified_files_path, git_repo_path)

    # 
    # Simulator libraries
    # 
    repo_name = 'simulator_libraries'
    repo_url = f'https://code.osu.edu/fehelectronics/proteus_software/{repo_name}.git'

    target_dir = f'FEH/{repo_name}'
    git_repo_path = os.path.join(os.getcwd(), target_dir)

    clone_repository(repo_url, target_dir)

    modified_files_path = f'install_scripts/mod_files/{repo_name}'
    replace_files(modified_files_path, git_repo_path)
