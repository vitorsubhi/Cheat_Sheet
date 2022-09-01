echo 'Username'
read -p "-> " name
echo 'E-mail'
read -p "-> " email
ssh-keygen -q -t rsa -b 4096 -N '' -f ~/.ssh/id_rsa
git config --global --replace-all user.email "${email}"
git config --global --replace-all user.name "${name}"
echo ''
echo 'Public Key into Clipboard(Ctrl+C, Ctrl+V):'
cat ~/.ssh/id_rsa.pub
clip < ~/.ssh/id_rsa.pub
explorer.exe https://github.com/settings/ssh/new
read -p "-> " exit