const input = document.getElementById('url-input') as HTMLInputElement;
const button = document.getElementById('shorten-btn') as HTMLButtonElement;
const result = document.getElementById('result') as HTMLDivElement;

button.onclick = async () => {
  const url = input.value.trim();
  if (!url) {
    result.style.display = 'block';
    result.textContent = 'Please enter a URL.';
    return;
  }
  // TODO: Replace with actual backend call
  // Example: const response = await fetch('/api/shorten', { ... })
  // For now, just mock a short URL
  const shortUrl = 'https://nano.url/' + Math.random().toString(36).substring(2, 8);
  result.style.display = 'block';
  result.innerHTML = `Shortened URL: <a href="${shortUrl}" target="_blank">${shortUrl}</a> <button id="copy-btn">Copy</button>`;
  const copyBtn = document.getElementById('copy-btn') as HTMLButtonElement;
  copyBtn.onclick = () => {
    navigator.clipboard.writeText(shortUrl);
    copyBtn.textContent = 'Copied!';
    setTimeout(() => {
      copyBtn.textContent = 'Copy';
    }, 1200);
  };
};
