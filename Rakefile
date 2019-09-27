require 'fileutils'

USERNAME  = 'my'
KEYBOARDS = {
  'kbdfans/kbd4x' => [nil],
  'georgi'        => [nil],
  'planck'        => ['rev3', 'rev4', 'rev5', 'light'],
  'preonic'       => ['rev3'],
}
QMK_DIR   = "#{__dir__}/qmk"
USER_DIR  = "#{QMK_DIR}/users/#{USERNAME}"

def keymap_dir(keyboard)
  "#{QMK_DIR}/keyboards/#{keyboard}/keymaps/#{USERNAME}"
end

task default: :install

desc 'Symlink keymap files into QMK source tree'
task :install do
  FileUtils.ln_s(File.expand_path('user', __dir__), USER_DIR, verbose: true) unless File.exist?(USER_DIR)

  KEYBOARDS.each_key do |keyboard|
    dest = keymap_dir(keyboard)
    FileUtils.ln_s(File.expand_path(keyboard, __dir__), dest, verbose: true) unless File.exist?(dest)
  end
end

desc 'Remove symlinks from QMK source tree'
task :uninstall do
  FileUtils.rm_r USER_DIR, verbose: true, force: true

  KEYBOARDS.each_key do |keyboard|
    FileUtils.rm_r keymap_dir(keyboard), verbose: true, force: true
  end
end

desc 'Remove build artifacts'
task :clean do
  Dir.chdir(QMK_DIR) { sh 'make clean' }
end

namespace :qmk do
  desc 'Install QMK dependencies'
  task :install do
    Dir.chdir(QMK_DIR) { sh 'util/qmk_install.sh' }
  end

  desc 'Update QMK firmware'
  task :update do
    Dir.chdir(QMK_DIR) do
      sh 'git pull --ff-only'
      sh 'make git-submodule'
    end
  end
end

desc 'Build all keymaps for CI'
task ci: :install do
  Dir.chdir(QMK_DIR) do
    KEYBOARDS.each do |keyboard, revisions|
      revisions.each do |revision|
        target = revision.nil? ? keyboard : "#{keyboard}/#{revision}"
        sh "make #{target}:#{USERNAME}"
      end
    end
  end
end

class Combo
  attr_accessor :keys, :action

  def initialize(keys, action)
    @keys = keys
    @action = action
  end

  def keys_slug
    @keys.collect {|key| key.sub(/^KC_/, '')}.join('_')
  end

  def constant_name
    "MY_COMBO_#{keys_slug}"
  end

  def array_name
    "combo_#{keys_slug}"
  end

  def simple?
    @action =~ /^\w+$/
  end

  def complex?
    !simple?
  end
end

desc 'Regenerate generated C files'
task :generate do
  require 'erb'
  require 'yaml'

  combos = YAML.load_file('combos.yaml').collect do |combo|
    Combo.new(combo['keys'], combo['action'])
  end

  Dir.glob('**/*.erb') do |path|
    File.write(path.sub(/\.erb$/, ''), ERB.new(File.read(path)).result(binding))
  end
end
